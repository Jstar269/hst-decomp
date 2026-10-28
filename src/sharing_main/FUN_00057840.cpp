/* HSTMATCH module=hstp_trans_main.prx start=0x00057840 end=0x00057904 symbol=FUN_00057840 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v12) corrected by hand: typed the helper calls and expressed virtual slot +0x10 as a C++ method; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02c4;
extern "C" void FUN_000579bc(int *);
extern "C" int * FUN_0005f898(int *);

struct V5
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2(u32,u32,u32,u32,u32,u32);
};

extern "C" int * FUN_00057840(int *param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  FUN_0005f898(param_1);
  *param_1 = (int)&DAT_003b02c4;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_000579bc(param_1);
  ((V5 *)param_1)->Slot2(param_2,param_3,param_4,param_5,param_6,param_7);
  return param_1;
}
