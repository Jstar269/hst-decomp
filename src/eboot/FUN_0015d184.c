/* HSTMATCH module=EBOOT.BIN start=0x0015d184 end=0x0015d1c8 symbol=FUN_0015d184 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340400;
extern u8 DAT_0034100c;

void FUN_0015d184(u32 param_1,int param_2)
{
  u8 bVar1;
  
  (&DAT_0034100c)[param_2] = 1;
  bVar1 = *(u8 *)(param_2 + DAT_00340400 + 0x10);
  if (bVar1 < 0xc9) {
    *(u8 *)(param_2 + DAT_00340400 + 0x10) = bVar1 + 1;
  }
}
