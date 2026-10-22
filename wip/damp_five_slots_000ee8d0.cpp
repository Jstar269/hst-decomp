/* HSTMATCH module=EBOOT.BIN start=0x000ee8d0 end=0x000eea50 symbol=FUN_000ee8d0 lang=c++ */
extern "C" float fabsf(float);
extern "C" float FUN_0000bb44(float);
extern "C" void FUN_000ffb3c(unsigned int, int);
extern "C" void FUN_00103128(int);
extern "C" void FUN_00103480(int);
extern "C" void FUN_0010f5d4(unsigned int, int);
extern unsigned char *DAT_003386b0;

struct VBase
{
  virtual void v0();
  virtual void v1(int);
};

extern "C" void FUN_000ee8d0(int param_1)
{
  if (*(unsigned char *)(param_1 + 0x54) == 0)
  {
    int p0 = *(int *)(param_1 + 0x5c);
    float f3 = *(float *)(p0 + 100);
    int p1 = *(int *)(param_1 + 0x60);
    float f5 = *(float *)(p1 + 100);
    float f8 = 0.0f;
    float f6 = f8 - f3;
    int p2 = *(int *)(param_1 + 100);
    int p3 = *(int *)(param_1 + 0x68);
    int p4 = *(int *)(param_1 + 0x6c);
    if (fabsf(f6) >= 0.1f)
    {
      f8 = f3 + f6 * 0.2f;
    }
    float fz = 0.0f;
    f6 = fz - f5;
    if (fabsf(f6) >= 0.1f)
    {
      fz = f5 + f6 * 0.2f;
    }
    *(float *)(p0 + 100) = f8;
    *(float *)(p1 + 100) = fz;
    *(float *)(p2 + 100) = f8;
    *(float *)(p3 + 100) = fz;
    *(float *)(p4 + 100) = f8;
    if (*(unsigned char *)(param_1 + 0x54) == 0)
    {
      FUN_00103480(param_1);
    }
    if (DAT_003386b0[0x68] != 0)
    {
      int n = (int)FUN_0000bb44((float)*(int *)(DAT_003386b0 + 0x6c) / 30.0f);
      ((VBase *)*(int *)(param_1 + 0x6c))->v1(0);
      FUN_0010f5d4(*(unsigned int *)(param_1 + 0xa0), n);
      if (n < 1)
      {
        FUN_000ffb3c(*(unsigned int *)(param_1 + 0x70), 1);
        FUN_000ffb3c(*(unsigned int *)(param_1 + 0x74), 1);
        FUN_000ffb3c(*(unsigned int *)(param_1 + 0x80), 1);
        FUN_000ffb3c(*(unsigned int *)(param_1 + 0x84), 1);
      }
    }
    FUN_00103128(param_1);
  }
}
// 6 words differ: (1) MWCC hoists the p0 (+0x5c) store into the second bc1t delay slot
//   and makes it bc1tl (retail: plain bc1t with nop, stores all after the body);
// (2) p2 (+0x64) pointer load is scheduled before p3/p4 in ours, retail defers it to
//   the first bc1t delay slot; (3) the p1 (+0x60) float load sits one slot later here.
// Registers already match (p2=a1,p3=a0,p4=v1, f8=f4, fz=f3). Ruled out: source store
// order permutations (A/B/C), moving the p2 read after the first if (D/E/F), an inline
// Damp() helper (gives neg.s), free-function virtual dispatch (v0 vs retail t9; C++
// virtual member matches t9). Header lang=c++ for the virtual call.
// near miss from lane od3 (unreviewed)
