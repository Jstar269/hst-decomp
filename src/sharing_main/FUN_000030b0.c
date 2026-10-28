/* HSTMATCH module=hstp_trans_main.prx start=0x000030b0 end=0x000030d0 symbol=FUN_000030b0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

int FUN_000030b0(void)
{
  int iVar1;
  
  iVar1 = FUN_000030a8();
  return iVar1 + 1;
}
