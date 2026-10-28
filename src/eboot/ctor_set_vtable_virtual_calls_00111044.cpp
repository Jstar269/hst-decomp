/* HSTMATCH module=EBOOT.BIN start=0x00111044 end=0x0011110c symbol=FUN_00111044 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the three indirect calls written as C++ virtual calls (slots 6 float 10.0f, 5 int -256, 1 int 0) on a polymorphic type; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1174;
extern u8 DAT_00307b6c;
extern u8 DAT_00307d94;
extern "C" void FUN_00100eb8(...);
extern "C" void FUN_001014e8(...);

struct VC_0 {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5(int);
  virtual void v6(float);
};

extern "C" int * FUN_00111044(int *param_1,u32 *param_2,u32 param_3)
{
  *param_1 = (int)&DAT_00307b6c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[8] = 0x47c35000;
  *(u8 *)(param_1 + 9) = 0;
  *param_1 = (int)&DAT_00307d94;
  param_1[10] = 0;
  FUN_00100eb8((int)param_1,param_2,param_3,(char *)0x0);
  FUN_001014e8((int)param_1,&DAT_002c1174,0x2a);
  ((VC_0 *)param_1)->v6(10.0f);
  ((VC_0 *)param_1)->v5(-256);
  ((VC_0 *)param_1)->v1(0);
  return param_1;
}
