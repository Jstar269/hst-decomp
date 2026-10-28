/* HSTMATCH module=hstp_trans_main.prx start=0x00119e58 end=0x00119f20 symbol=FUN_00119e58 lang=c++ */
/* Clone of src/eboot/ctor_set_vtable_virtual_calls_00111044.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the three indirect calls written as C++ virtual calls (slots 6 float 10.0f, 5 int -256, 1 int 0) on a polymorphic type; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d1554;
extern u8 DAT_003b0e38;
extern u8 DAT_003b1060;
extern "C" void FUN_001067c0(...);
extern "C" void FUN_00106ec0(...);

struct VC_0 {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5(int);
  virtual void v6(float);
};

extern "C" int * FUN_00119e58(int *param_1,u32 *param_2,u32 param_3)
{
  *param_1 = (int)&DAT_003b0e38;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[8] = 0x47c35000;
  *(u8 *)(param_1 + 9) = 0;
  *param_1 = (int)&DAT_003b1060;
  param_1[10] = 0;
  FUN_001067c0((int)param_1,param_2,param_3,(char *)0x0);
  FUN_00106ec0((int)param_1,&DAT_002d1554,0x2a);
  ((VC_0 *)param_1)->v6(10.0f);
  ((VC_0 *)param_1)->v5(-256);
  ((VC_0 *)param_1)->v1(0);
  return param_1;
}
