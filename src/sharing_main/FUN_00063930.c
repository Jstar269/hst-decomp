/* HSTMATCH module=hstp_trans_main.prx start=0x00063930 end=0x00063960 symbol=FUN_00063930 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00078d90();

bool FUN_00063930(int param_1)
{
  bool bVar1;
  u32 uVar2;
  
  if (param_1 < 0) {
    bVar1 = false;
  }
  else {
    uVar2 = FUN_00078d90();
    bVar1 = (uVar2 & 3) != 0;
  }
  return bVar1;
}
