/* HSTMATCH module=EBOOT.BIN start=0x001b2af0 end=0x001b2bb8 symbol=FUN_001b2af0 lang=c++ */
extern "C" float DAT_002e515c[];
extern "C" int FUN_000627e8(int, int);
extern "C" int FUN_00062a6c(int);
extern "C" void FUN_00062a9c(int, int, int);
extern "C" int FUN_001b2af0(int *param_1, int param_2)
{
    int idx = param_2 + 0x32;
    int base = *param_1;
    int id;
    bool ok;
    float f;

    ok = idx < 0x1da && *(int *)(base + idx * 4) != 0;
    if (!ok) {
        id = -1;
    } else {
        id = FUN_000627e8(*(int *)(base + idx * 4), 0);
        f = DAT_002e515c[idx];
        ok = id >= 0 && FUN_00062a6c(id) != 0;
        if (!ok)
            id = -1;
        else
            FUN_00062a9c(id, (int)(f * 128.0f), (int)(f * 128.0f));
    }
    return id;
}
// near miss: 51/50 words, 34 differ. This is the closest shape so far and it is C++ (`bool ok`), not
// C: the entry flag has to be a `bool` assigned from the whole `idx < 0x1da && slot != 0` expression
// so MWCC materialses it with `sltu v0,zero,v0` and branches `bnezl v0,BODY` with `sll s0,v1,2` in
// the delay. Two more requirements: the OUTER test is the inverted `if (!ok) { id = -1; } else {
// body }` (the natural `if (ok) {body} else {id=-1}` emits `beqzl v0,EPILOGUE` with the `li s1,-1`
// in its delay and loses the separate `b EPILOGUE; li s1,-1` block), and `*param_1` is hoisted into
// an `int base` local so the base pointer stays live across the branch in a0. What is still off:
// MWCC folds `param_2 + 0x32` into the incoming a1 and loads the base into v1, where retail keeps
// the index in v1 and the base in a0 (retail's `lw a0,0(a0)`), and the body then reads one word
// more. Ruled out: the C `int ok` forms (49 words, `beqzl a0` fold), two-step `ok = 0; if (...) ok
// = ...;`, `bool ok = false;` init, `unsigned` index, `param_2 += 0x32`, and inlining `param_2 + 0x32`
// at every use (54 words).
// near miss from lane fm6 (unreviewed)
