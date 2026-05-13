options gen2
expect 30341    // function_not_found: shorthand var names don't match target tuple field names

require dastest/testing_boost public

// issue #2641: shorthand named-tuple from variable refs requires the variable names
// to match the target named-tuple field names. Here `foo`/`bar` don't match
// `eid`/`distSq`, so the call must not resolve.
def fail_name_mismatch() {
    var arr : array<tuple<eid : int; distSq : float>>
    let foo = 1
    let bar = 1.1
    arr |> push((foo, bar))
}
