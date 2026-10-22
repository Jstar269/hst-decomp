/* HSTMATCH module=EBOOT.BIN start=0x002951a0 end=0x00295208 symbol=FUN_002951a0 lang=c99 */
extern int DAT_002cae44[];
extern int DAT_002cae5c[];
extern int FUN_002b79a8(int);
extern void FUN_00294684(int *, int);

void FUN_002951a0(int param_1)
{
  int r;

  if (*(int *)(param_1 + 0x24) >= 0) {
    r = FUN_002b79a8(*(int *)(param_1 + 0x24));
    if (r)
      FUN_00294684(DAT_002cae5c, r);
    else
      FUN_00294684(DAT_002cae44, *(int *)(param_1 + 0x24));
    *(int *)(param_1 + 0x24) = -1;
  }
}

// NEAR MISS: 26/26 words, 5 words differ (best of 4 compiles).
// Retail copies the call result into a1 right after the jal (`move a1,v0`), tests a1
// (`beqzl a1,SUCCESS`), then falls through into the error call with a1 already in place and the
// success block reloading the thread id into a1. Ours keeps the result in v0 (`beqzl v0`), so the
// `move a1,v0` lands later and every following branch target shifts by one slot.
// Ruled out: `if (r == 0) success else error` (bnezl, block order flips), `if (r)` for `if (r != 0)`,
// `-1 < id` instead of `id >= 0` (gives slti at instead of bltzl).
// near miss from lane fm2 (unreviewed)
