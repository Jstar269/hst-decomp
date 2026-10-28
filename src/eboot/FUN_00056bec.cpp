/* HSTMATCH module=EBOOT.BIN start=0x00056bec end=0x00056cb0 symbol=FUN_00056bec lang=c++ */
/* Clone of src/sharing_main/FUN_00057840.cpp (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v12) corrected by hand: typed the helper calls and expressed virtual slot +0x10 as a C++ method; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306ff8;
extern "C" void FUN_00056d68(int *);
extern "C" int * FUN_0005eaa8(int *);

struct V5
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2(u32,u32,u32,u32,u32,u32);
};

extern "C" int * FUN_00056bec(int *param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  FUN_0005eaa8(param_1);
  *param_1 = (int)&DAT_00306ff8;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_00056d68(param_1);
  ((V5 *)param_1)->Slot2(param_2,param_3,param_4,param_5,param_6,param_7);
  return param_1;
}
