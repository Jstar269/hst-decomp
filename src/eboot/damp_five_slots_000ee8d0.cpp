/* HSTMATCH module=EBOOT.BIN start=0x000ee8d0 end=0x000eea50 symbol=FUN_000ee8d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
    int p2 = *(int *)(param_1 + 100);
    int p3 = *(int *)(param_1 + 0x68);
    int p4 = *(int *)(param_1 + 0x6c);
    float f5 = *(float *)(p1 + 100);
    float f8 = 0.0f;
    float f6 = f8 - f3;
    f8 = (fabsf(f6) >= 0.1f) ? (f3 + f6 * 0.2f) : f8;
    float fz = 0.0f;
    f6 = fz - f5;
    fz = (fabsf(f6) >= 0.1f) ? (f5 + f6 * 0.2f) : fz;
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
