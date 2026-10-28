/* HSTMATCH module=hstp_trans_main.prx start=0x00003088 end=0x000030a8 symbol=FUN_00003088 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

u32 FUN_00003088(void)
{
  int iVar1;
  
  iVar1 = FUN_000030a8();
  return *(u32 *)(iVar1 + 8);
}
