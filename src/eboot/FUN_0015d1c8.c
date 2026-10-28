/* HSTMATCH module=EBOOT.BIN start=0x0015d1c8 end=0x0015d1e8 symbol=FUN_0015d1c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340400;

u8 FUN_0015d1c8(u32 param_1,int param_2)
{
  u8 uVar1;
  
  uVar1 = 0;
  if (DAT_00340400 != 0) {
    uVar1 = *(u8 *)(param_2 + DAT_00340400 + 0x10);
  }
  return uVar1;
}
