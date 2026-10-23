/* HSTMATCH module=hstp_trans_main.prx start=0x000f3f98 end=0x000f4118 symbol=FUN_000f3f98 lang=c++ */
/* Clone of src/eboot/damp_five_slots_000ee8d0.cpp (hstclone.py tag sw1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" float fabsf(float);
extern "C" float FUN_0000bb5c(float);
extern "C" void FUN_00105470(unsigned int, int);
extern "C" void FUN_00108a2c(int);
extern "C" void FUN_00108dac(int);
extern "C" void FUN_00116fd4(unsigned int, int);
extern unsigned char *DAT_003e19f0;

struct VBase
{
  virtual void v0();
  virtual void v1(int);
};

extern "C" void FUN_000f3f98(int param_1)
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
      FUN_00108dac(param_1);
    }
    if (DAT_003e19f0[0x68] != 0)
    {
      int n = (int)FUN_0000bb5c((float)*(int *)(DAT_003e19f0 + 0x6c) / 30.0f);
      ((VBase *)*(int *)(param_1 + 0x6c))->v1(0);
      FUN_00116fd4(*(unsigned int *)(param_1 + 0xa0), n);
      if (n < 1)
      {
        FUN_00105470(*(unsigned int *)(param_1 + 0x70), 1);
        FUN_00105470(*(unsigned int *)(param_1 + 0x74), 1);
        FUN_00105470(*(unsigned int *)(param_1 + 0x80), 1);
        FUN_00105470(*(unsigned int *)(param_1 + 0x84), 1);
      }
    }
    FUN_00108a2c(param_1);
  }
}
