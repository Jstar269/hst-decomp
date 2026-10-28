/* HSTMATCH module=hstp_trans_main.prx start=0x00003c50 end=0x00003c74 symbol=FUN_00003c50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

u32 FUN_00003c50(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_000030a8();
  return *puVar1 >> 1;
}
