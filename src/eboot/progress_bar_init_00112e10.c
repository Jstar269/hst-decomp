/* HSTMATCH module=EBOOT.BIN start=0x00112e10 end=0x00112ed8 symbol=FUN_00112e10 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The `param_1[2] > 15` spelling is needed for retail's `slti at`/`bnezl at` (writing `>= 0x10` puts the
   compare in v1); `i = 0` is initialised before the `0 < n` guard and the source-cell index is computed
   before the -999 test so its multiply lands in the likely-branch delay slot. */
#pragma opt_strength_reduction off
extern void FUN_00112c94(char *, ...);
extern char DAT_002d92ec;
extern char DAT_002d9324;

void FUN_00112e10(int *param_1, int param_2, int param_3, int param_4)
{
  int i;
  int idx;
  int *p;

  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = param_4;
  if (*(int *)(*param_1 + 0x14) < 1) {
    FUN_00112c94(&DAT_002d92ec);
  }
  else if (param_1[2] > 15) {
    FUN_00112c94(&DAT_002d9324);
  }
  else {
    i = 0;
    if (0 < param_4) {
    p = param_1;
    do {
      int idx = param_1[1] + i * param_1[2];
      if (p[4] == -999) {
        p[4] = *(int *)(*(int *)(*(int *)(*param_1 + 0x10) + idx * 4) + 0x24);
      }
      *(char *)((int)param_1 + i + 0x5b) = 0;
      *(char *)((int)param_1 + i + 0x6a) = 0;
      i = i + 1;
      p = p + 1;
    } while (i < param_4);
    }
  }
  return;
}
