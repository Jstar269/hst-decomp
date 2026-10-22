/* HSTMATCH module=EBOOT.BIN start=0x0022af6c end=0x0022aff4 symbol=FUN_0022af6c lang=c99 */
extern char *DAT_003415a8;
extern int FUN_0022a9a8(int, int);

int FUN_0022af6c(int param_1, int param_2)
{
  unsigned char v;

  if (FUN_0022a9a8(param_1, param_2) == 1) {
    char *p = (char *)DAT_003415a8 + param_1 * 20 + (param_2 + 10);
    v = *(unsigned char *)(p + 0x3d00);
  }
  else {
    char *p = (char *)DAT_003415a8 + param_1 * 20 + param_2;
    v = *(unsigned char *)(p + 0x3d00);
  }
  return v == 0;
}

// NEAR MISS: 34 words, 19 differ (best of 6 compiles).
// Both branches are `v = *(unsigned char *)(DAT[param_1*20] + param_2 [+10] + 0x3d00)` and the
// `return v == 0;` tail matches. Differences: retail emits `lui` x2 first, then `lw a0` (then-path
// base), `addiu v1,s0,10`, then the 20*idx chain (sll/addu/sll) and `addu v0,v1,v0`; ours emits a
// stray duplicate `sll v0,s1,2` before the `lui`/`lw` (CSE split across the two branches) and adds
// the base before the +10 term. Ruled out: folding 10 into the displacement (`addiu v1,s0,15626`),
// a named `int k = param_2+10` inside the then-block, a per-branch `char *p` + `p[0x3d00]`,
// swapping the sum order both ways.
// near miss from lane fm2 (unreviewed)
