/* HSTMATCH module=EBOOT.BIN start=0x000b34d8 end=0x000b3558 symbol=FUN_000b34d8 lang=c99 */
extern int FUN_000b3558(int);
extern int DAT_002d4360;

int FUN_000b34d8(int param_1)
{
  int *p;
  int *q;
  float f;
  if (FUN_000b3558(param_1) != 0) {
    p = *(int **)(param_1 + 0x5bc);
    q = *(int **)((char *)p + 0x58);
    if (q) f = *(float *)((char *)q + 0x104);
    else f = 0.0f;
    if (f == (float)(3 - DAT_002d4360)) return 1;
  }
  return 0;
}
// near miss: 20 of 32 words differ; retail's float arm is `beqzl; mtc1(delay); b JOIN; lwc1(delay)` (extra
// b and a dead mtc1 at the join) and its tail is `bc1t epi; li v0,1; move v0,zero; b epi+4; lw ra(delay)`
// (ours: bc1f + separate epilogue). Ruled out: ternary, explicit else, value-returning `r`, inline getter,
// `f=0.0f; if(q) f=q->f;`, `if(q==0)f=0;else f=q->f;`, `if(q)f=..;else f=0.0f;`, 11 more shapes.
// near miss from lane ds4 (unreviewed)
