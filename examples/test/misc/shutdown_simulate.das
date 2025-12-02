
module shutdown_simulate

require daslib/ast_boost
require rtti

let shared DLL : void? = null;
let shared public MainCtx : void? = null;

[init]
def setup {
    this_context().name := "Test macro ctx"
    print("Call setup in simulate\n")
}

[no_jit, finalize]
def done {
    if ( get_context_share_counter() == 1ul ) { // IF THIS ONE IS THE LAST ONE
        print("Done sim with dll={DLL}\n")
    }
}



[simulate_macro(name="test")]
class EmptySim : AstSimulateMacro {
    def override simulate(prog : Program?; var ctx : Context?) : bool {
        print("init from simulate\n")
        unsafe {
            reinterpret<void?>(DLL) = reinterpret<void?>(0x12345678)
        }
        return true
    }
}