/* HSTMATCH module=EBOOT.BIN start=0x0028df14 end=0x0028e02c symbol=FUN_0028df14 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the virtual dispatches, float argument, and module data address; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern "C" void FUN_0001dfe8(int,int);
extern "C" void FUN_0001e23c(int,int,int);
extern "C" void FUN_00103540(float,int *);
extern "C" void FUN_00103628(int *,int);
extern "C" void FUN_001037c8(int *,int);
extern "C" void FUN_001b3ce8(int *,int);
extern "C" void FUN_00280830(int,int,int);
extern "C" void FUN_00281128(int);
extern "C" void FUN_002817e0(int);
extern "C" void FUN_0028e074(int *,int);
extern "C" int DAT_0034179c;

struct V30 {
  virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
  virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
  virtual void m8(); virtual void m9(); virtual void m10();
};
struct V10 { virtual void m0(); virtual void m1(); virtual void m2(); };
struct V0C { virtual void m0(); virtual void m1(int); };

extern "C" void FUN_0028df14(int *param_1)
{
  FUN_00281128(param_1[400]);
  FUN_00280830(param_1[400],2,1);
  *(u32 *)(param_1[400] + 0x61c) = 1;
  *(u8 *)(param_1[400] + 0x615) = 1;
  FUN_002817e0(param_1[400]);
  FUN_00103540(1010.0f,param_1);
  FUN_001037c8(param_1,0xffffffff);
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  if ((int *)param_1[0x16] != (int *)0x0) {
    ((V30 *)param_1[0x16])->m10();
  }
  *(u8 *)(param_1 + 0x15) = 1;
  *(u8 *)((int)param_1 + 0x55) = 0;
  FUN_00103628(param_1,0);
  ((V10 *)param_1)->m2();
  FUN_001037c8(param_1,0x10);
  ((V0C *)param_1[0x197])->m1(1);
  FUN_0028e074(param_1,0);
  FUN_001b3ce8(&DAT_0034179c,4);
}
