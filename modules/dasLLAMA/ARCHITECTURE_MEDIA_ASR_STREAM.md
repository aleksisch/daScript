# dasLLAMA Architecture - streaming speech recognition

Companion to `ARCHITECTURE_MEDIA_ASR.md`; a section is cited by its anchor. This document carries
NVIDIA's cache-aware streaming FastConformer (Nemotron ASR) on Parakeet's loader
(`#nemotron-carrier`), its stream (`#nemotron-stream`), the FastConformer block's streaming form
(`#fc-stream-block`) and the transducer decode that goes on across chunks (`#rnnt-stream-continue`).

### Nemotron is a Parakeet variant read off NeMo's own GGUF {#nemotron-carrier}

NVIDIA ships the model as a GGUF of architecture `asr` under NeMo's own tensor names and
hyperparameters (`asr.*` keys). `pk_gguf_header` hands that architecture to `pk_nemo_header`, which
fills the same `ParakeetStaging` the bin and the `parakeet` GGUF fill, sets ``nemotron`` and reads the
names as stored (`PkSource.nemo`). The variant differs from Parakeet-TDT where the stream needs it:

- The conv module's norm is a LayerNorm stored under the BatchNorm's name, so no running statistics
  are folded, and its depthwise conv is causal (`#fc-stream-block`).
- The front's three stride-2 convs pad (2, 1) on time and on the mel bins, so each takes a width to
  half plus one (`pk_front_width`), where Parakeet's centred convs halve it.
- The head is a plain RNN-T: no duration table, and the predictor's two torch biases are summed
  into the one the net reads.
- A prompt projector (`prompt_kernel`) sits between the encoder and the joint: ReLU(W1 [x; onehot])
  then W2, the one-hot naming the language from the carrier's `asr.rnnt.prompt_dictionary`
  (``prompts``, `"<locale>:<index>"`).
- The carrier holds its own mel filterbank (`preprocessor.fb`) and the window length.

The header refuses, naming the key, every configuration the chain does not run: another head, a
model without cache support, a conv norm, conv context, attention context style or feature
normalization other than `layer_norm`, `causal`, `chunked_limited` and `NA`, linear biases or input
scaling, an FF other than four times the width, a front other than 8x, a joint other than the
predictor's width, and a front end off 16 kHz. A Nemotron model loads through the image rail on the
CPU image alone (`load_nemotron_model`): the stream runs the CPU block chain, which no GPU flavor
serves.

### A stream keeps every stage's past and decodes a chunk of frames at a time {#nemotron-stream}

`nemotron_stream_feed` takes audio as it arrives and decodes every chunk of `lookahead + 1` encoder
frames the audio completes; the lookahead is the model's right context (0, 3, 6 or 13 frames, an
80, 320, 560 or 1120 ms chunk). Each stage keeps only what the next chunk reads from the past:

- **Mel.** Pre-emphasis 0.97 carries the last sample over a feed. Frame `i` is the 400-sample Hann
  window centred on sample `160 i` inside a 512-point frame (the STFT's centring pad, 256, of zeros
  before the stream), its power spectrum through the carrier's filterbank, `log(x + 2^-24)`, with no
  per-feature normalization. A frame is computed once its window's last sample has arrived; the
  samples before the next frame's window are dropped.
- **Front.** Row `j` of a stride-2 conv reads its input rows `2j - 2` to `2j`, so it is computed once
  row `2j` exists; each stage keeps its input rows from `2j - 2` of the next row on. Conv 0 maps one
  channel to the front's channels, each of the two separable stages runs a depthwise k3 stride-2
  conv then the pointwise channel mix, all with a ReLU, and the last stage's rows wait as feature
  rows `[t][c w + w]` for the encoder.
- **Encoder.** A chunk's rows run the pre-projection, then every block over the block's cached
  window (`#fc-stream-block`), then the prompt projector, whose one-hot column is folded into the
  first bias at `nemotron_stream_start`, and the joint's encoder half.
- **Decode.** The greedy RNN-T goes on from the last chunk's state (`#rnnt-stream-continue`); the
  tokens' frames count from the stream's start.

`flush` ends the stream: the frames past the audio's end are zeros, the convs read the one row past
their input as the right pad's zero, and the last, shorter chunk decodes. A stream decoded this way
is the offline model under its `chunked_limited` attention mask, chunk for chunk; how the audio is
split into feeds changes nothing. `nemotron_text` joins the pieces, their word marks as spaces and
the language tags the `auto` prompt emits left out.

### The FastConformer block streams over a cached window and a causal conv {#fc-stream-block}

`fc_block_cpu` takes the stream as its position type: `FcStreamPos` names the block, the rows its
window holds and the window's cap (the carrier's `train_left_ctx`). The attention's queries are the
chunk's rows; its keys and values are the window's cached rows followed by the chunk's own, every
query reading all of them, with the Transformer-XL rel-pos scores over a table of the window's
length (`parakeet_pos_table` over the window's rows). The block then keeps the window's last `cap`
rows in the state (``kvc_k``/``kvc_v``, `cap` rows a block).

The form's ``causal`` flag makes the conv module's depthwise conv read only the past: the block's
`k - 1` GLU rows before the chunk (``cvc``, zeros at the stream's start) then the chunk's own, through
`fc_dw_causal_rows`, followed by the LayerNorm and the SiLU. Both caches live on the family's state
struct; a state without them panics at the first streaming block.

### A transducer stream goes on where its last chunk stopped {#rnnt-stream-continue}

`rnnt_greedy` with `fresh` false decodes a chunk's frames from the state the last call left, so a
stream decoded chunk by chunk emits the tokens, frames and log-probabilities of one call over the
whole clip. Two things cross a chunk's end in ``RnntState``: ``carry``, the step the next chunk
opens on - the token whose predictor step the end cut off when the chunk's last frame ended on the
symbol cap, else the joint alone at the new frame - and ``skip``, the frames a duration ran past the
end, which the next chunk passes over before its first step. A fresh call resets both, so a
whole-clip decode takes the same steps it always did.
