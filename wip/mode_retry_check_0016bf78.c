/* HSTMATCH module=EBOOT.BIN start=0x0016bf78 end=0x0016c030 symbol=FUN_0016bf78 lang=c99 */
extern int DAT_0034a678;
extern int FUN_002346e0(int *);
extern int FUN_0023471c(int *);

int FUN_0016bf78(int param_1)
{
  int v;

  if (DAT_0034a678 == 0x24) return 0;
  if (DAT_0034a678 == 0x55) return param_1;
  {
    if (param_1 != 0) {
      v = FUN_0023471c(&DAT_0034a678);
      switch (v) {
      case 0x29:
      case 0x30:
        return 0;
      }
      return 1;
    }
    else {
      v = FUN_002346e0(&DAT_0034a678);
      switch (v) {
      case 0x29:
      case 0x30:
        return 0;
      }
      return 1;
    }
  }
}

// NEAR MISS: 45/46 words, 22 differing words, all of them branch offsets plus the tail
// layout of the second body.  The three-way structure is right: `if (DAT_0034a678 == 0x24)
// return 0;` as a likely branch over `b EPILOGUE; move v0,zero`, the `== 0x55` test as an
// EARLY RETURN (`bne v1,v0,BODY; nop; b EPILOGUE; move v0,a0` - the `if (DAT != 0x55) {..}`
// form gives a likely branch instead), then two duplicated bodies (param_1 != 0 calls
// 0x23471c first, param_1 == 0 calls 0x2346e0 out of line at the end).
// What is not reachable: the 0x30/0x29 pair must be a two-case SWITCH (`case 0x29: case
// 0x30: return 0;`), because `if (v == 0x30) return 0; if (v == 0x29) return 0; return 1;`
// (also with else-if, also as a single `||`) folds to `xori v0,v0,0x29; sltu v0,zero,v0`.
// With the switch the compare pair matches, but retail's SECOND body ends
// `move v0,zero; b EPILOGUE; nop; li v0,1` (zero block first, the shared `li v0,1` last)
// while ours emits the return-1 block (b + li in the slot) before the zero block, and the
// first body's `return 1` lands on a `b EPILOGUE; nop` trampoline instead of jumping
// straight to the epilogue with `li v0,1` in the delay slot: one word short overall.
// Ruled out: body order swapped (23 words), `int v` declared per branch (22, unchanged),
// Ghidra's assign-param_1-then-single-return shape, plain if/else instead of else-if.
// near miss from lane fm5 (unreviewed)
