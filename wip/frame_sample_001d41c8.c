/* HSTMATCH module=EBOOT.BIN start=0x001d41c8 end=0x001d42f0 symbol=FUN_001d41c8 lang=c99 */
typedef unsigned int undefined4;

extern void *FUN_000e74e4(void *, void *, void *, void *, void *);
extern void FUN_000e74d4(void *, int, void *);
extern void *FUN_0006de18(void *, float, float, float, float);
extern void FUN_000c3f84(void *, void *, void *);

float FUN_001d41c8(int param_1, int param_2, int param_3)
{
  undefined4 auStack_40[16];
  undefined4 auStack_50[4];
  float fVar5;
  int idx;
  void *p;
  float fVar1;
  float t2;
  float t3;

  fVar5 = *(float *)(param_1 + 0x270) + (float)*(int *)(param_1 + 0xd4) +
          (float)param_3 * (6.0f / (float)*(int *)(param_1 + 0x51c));
  if (fVar5 >= 6.0f) {
    fVar5 = fVar5 - 6.0f;
  }
  idx = (int)fVar5;
  idx = ((unsigned)idx > 8) ? 8 : idx;
  fVar5 = fVar5 - (float)idx;
  p = FUN_000e74e4(auStack_40, (void *)((idx << 4) + param_1 + 0x1e0),
                   (void *)(((idx + 1) << 4) + param_1 + 0x1e0),
                   (void *)(((idx + 2) << 4) + param_1 + 0x1e0),
                   (void *)(((idx + 3) << 4) + param_1 + 0x1e0));
  FUN_000e74d4((void *)(param_1 + 400), *(int *)(param_1 + 0x1d0), p);
  t2 = fVar5 * fVar5;
  t3 = t2 * fVar5;
  p = FUN_0006de18(auStack_50, t3, t2, fVar5, 1.0f);
  FUN_000c3f84((void *)param_2, p, (void *)(param_1 + 400));
  fVar1 = *(float *)(param_2 + 0xc);
  *(float *)(param_2 + 0xc) = 1.0f;
  return fVar1;
}
// NEAR MISS: 18/74 words differ. Everything from the prologue to the wrap test matches; the whole
// diff is the clamped-index register (retail keeps the trunc/clamp result in a0 and the compare
// result in v0 with a plain `bnez`+nop slot; we get v1 and `at`/v0 with a likely form) plus the
// two words around the last call (retail move a1,v0 before addiu a2,s1,400).
// Ruled out for the clamp: if ((unsigned)idx > 8) idx = 8 / >= 9 / ternary both ways / int m = ...
// bool / unsigned idx / empty-then if / != 0 forms / inline helper taking int, unsigned, float
// (params land in v1 too) / idx declared first. Nothing moved the value out of v1.
// Ruled out for the tail: writing the cube as t*t*t (gives mul.s f12,f20,f13); t2/t3 locals are
// what retail has (mul.s f12,f13,f20) - that part is fixed and stable.
// near miss from lane fm3 (unreviewed)
