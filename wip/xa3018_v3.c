/* HSTMATCH module=EBOOT.BIN start=0x000a3018 end=0x000a3054 symbol=FUN_000a3018 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* NEAR 2/15 words (pass 73-74, 21 compiles; was 7 before the switch-order finding).
   Two mechanisms, both measured:
   (1) MWCC tests a small switch's cases in REVERSE source order, so `case 11` is listed
       before `case 1` to get retail's `li v0,1 ... li v1,11` chain (7 -> 4 differ).
   (2) A LABELLED GOTO TAIL forces one shared `move v0,zero` epilogue block at 0xa3048
       instead of letting MWCC inline the zero into each beql/beqzl slot (4 -> 2 differ).
   Residual (2 words at +0x10): the `a == 11` test compiles to `beql a0,v1` + slot
   `move v0,zero`; retail has plain `beq a0,v1,0xa3048` + nop. Six independent source
   shapes produce byte-identical code here (goto tail, case-1 switch + if-goto, single
   `||` goto, switch default-arm wrapper, b-as-switch, and the plain switch park), so the
   branch-likely choice for this one compare is a peephole decision, not source-steerable.
   Ruled out: if-chain (16/15), else-if chain (18/15), `||` chains (13/15), do/while(0)
   with breaks (18/15), single result variable (20/15), if+switch mixes, b-tests-first. */
int FUN_000a3018(int a, int b)
{
    switch (a) {
    case 11:
        return 0;
    case 1:
        return 0;
    }
    if (b == 0) goto zero;
    if (b == 1) goto zero;
    return 1;
zero:
    return 0;
}
// near miss from lane dsn3 (unreviewed)
