/* HSTMATCH module=EBOOT.BIN start=0x000649c0 end=0x00064a08 symbol=FUN_000649c0 lang=c++ */
/* Clone of src/sharing_main/FUN_00065884.cpp (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed virtual slot +0x0c as a C++ method call; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003070cc;

struct V4
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
};

extern "C" int * FUN_000649c0(int *param_1)
{
  *param_1 = (int)&DAT_003070cc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ((V4 *)param_1)->Slot1();
  return param_1;
}
