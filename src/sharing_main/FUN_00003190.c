/* HSTMATCH module=hstp_trans_main.prx start=0x00003190 end=0x000031b0 symbol=FUN_00003190 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003004();

int FUN_00003190(void)
{
  int iVar1;
  
  iVar1 = FUN_00003004();
  return iVar1 + 4;
}
