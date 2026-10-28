/* HSTMATCH module=hstp_trans_main.prx start=0x00002fc0 end=0x00002fe8 symbol=FUN_00002fc0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00002fe8();

void FUN_00002fc0(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00002fe8();
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
}
