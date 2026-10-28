/* HSTMATCH module=hstp_trans_main.prx start=0x000030d0 end=0x000030f8 symbol=FUN_000030d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

bool FUN_000030d0(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_000030a8();
  return (*puVar1 & 1) != 0;
}
