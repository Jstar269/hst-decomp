/* HSTMATCH module=hstp_trans_main.prx start=0x0029f6dc end=0x0029f7f4 symbol=FUN_0029f6dc lang=c++ */
/* Clone of src/eboot/initialize_route_0028df14.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the virtual dispatches, float argument, and module data address; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern "C" void FUN_0001dc34(int,int);
extern "C" void FUN_0001de88(int,int,int);
extern "C" void FUN_00108e6c(float,int *);
extern "C" void FUN_00108f54(int *,int);
extern "C" void FUN_001090f4(int *,int);
extern "C" void FUN_001c1f44(int *,int);
extern "C" void FUN_00291b78(int,int,int);
extern "C" void FUN_002924a0(int);
extern "C" void FUN_00292bf8(int);
extern "C" void FUN_0029f83c(int *,int);
extern "C" int DAT_003eaad8;

struct V30 {
  virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
  virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
  virtual void m8(); virtual void m9(); virtual void m10();
};
struct V10 { virtual void m0(); virtual void m1(); virtual void m2(); };
struct V0C { virtual void m0(); virtual void m1(int); };

extern "C" void FUN_0029f6dc(int *param_1)
{
  FUN_002924a0(param_1[400]);
  FUN_00291b78(param_1[400],2,1);
  *(u32 *)(param_1[400] + 0x61c) = 1;
  *(u8 *)(param_1[400] + 0x615) = 1;
  FUN_00292bf8(param_1[400]);
  FUN_00108e6c(1010.0f,param_1);
  FUN_001090f4(param_1,0xffffffff);
  FUN_0001dc34(DAT_003751d4,0x2000);
  FUN_0001de88(DAT_003751d4,0x2000,1);
  if ((int *)param_1[0x16] != (int *)0x0) {
    ((V30 *)param_1[0x16])->m10();
  }
  *(u8 *)(param_1 + 0x15) = 1;
  *(u8 *)((int)param_1 + 0x55) = 0;
  FUN_00108f54(param_1,0);
  ((V10 *)param_1)->m2();
  FUN_001090f4(param_1,0x10);
  ((V0C *)param_1[0x197])->m1(1);
  FUN_0029f83c(param_1,0);
  FUN_001c1f44(&DAT_003eaad8,4);
}
