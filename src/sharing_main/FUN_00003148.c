/* HSTMATCH module=hstp_trans_main.prx start=0x00003148 end=0x00003168 symbol=FUN_00003148 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

int FUN_00003148(void)
{
  int iVar1;
  
  iVar1 = FUN_000030a8();
  return iVar1 + 4;
}
