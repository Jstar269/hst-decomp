/* HSTMATCH module=EBOOT.BIN start=0x0022c334 end=0x0022c484 symbol=FUN_0022c334 lang=c99 */

extern unsigned char DAT_003415a8[];
extern char DAT_002f2b9c[];
int FUN_00193118(void);
int FUN_0019319c(void);
int FUN_001930c4(int);
int FUN_0022a9a8(int, int);
void FUN_0022c308(char *, int, int, int);

int FUN_0022c334(int param_1)
{
  int ref;
  int i;
  int n;
  int rec;
  int a;
  int b;
  int k;
  unsigned char pct;
  int r;

  r = 1;
  ref = 0;
  if (param_1 != 0) {
    ref = FUN_00193118();
  }
  i = 0;
  n = FUN_0019319c();
  while (i < n) {
    rec = FUN_001930c4(i);
    if ((ref == 0 || *(short *)(rec + 0x10) != *(short *)(ref + 0x10)) &&
        *(char *)(rec + 0x2f) > 0 && *(char *)(rec + 0x2f) < 0xb) {
      b = *(short *)(rec + 0x38);
      a = *(short *)(rec + 0x36);
      k = FUN_0022a9a8(a, b);
      if (k == 1) {
        pct = DAT_003415a8[a * 0x14 + b + 0x3d0f];
      } else {
        pct = DAT_003415a8[a * 0x14 + b + 0x3d05];
      }
      if (pct < 100) {
        FUN_0022c308(DAT_002f2b9c, *(unsigned short *)(rec + 0x10), a, b);
        return 0;
      }
    }
    i++;
    n = FUN_0019319c();
  }
  return r;
}
// NEAR 81/84 words (0x0022c334). All the pieces are in place: the optional reference record from
// FUN_00193118, the count from FUN_0019319c, the per-entry skip test (different id, 0 < f2f < 0xb),
// the two percentage bytes at 0x3d0f/0x3d05 chosen by FUN_0022a9a8, the "< 100" test, the
// VSList_Com_not_perfect_Match log and the 1/0 returns.
// What is wrong: retail keeps the 1 in a callee-saved register from the prologue (`li s5,1` in the
// beqz delay) and tests the count with `blezl v0,end` at the loop entry, then re-reads the count at
// the bottom (for-loop form) with the index in s4; ours keeps the constant as an immediate, checks
// the count at the top of a while, and uses five saved registers instead of six. A `int r = 1;`
// result variable plus `return r;` did not change it.
// near miss from lane fm5 (unreviewed)
