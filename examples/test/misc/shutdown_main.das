require shutdown_simulate
require rtti

[init]
def setup {
    this_context().name := "Main ctx"
    print("Setup main function\n")
}

[export]
def main() {
    print("Main function\n")
}

[no_jit, finalize]
def done {
    if ( get_context_share_counter() == 1ul ) { // IF THIS ONE IS THE LAST ONE
        print("Done with main dll={DLL}\n")
    }
}
