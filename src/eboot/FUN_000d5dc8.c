/* HSTMATCH module=EBOOT.BIN start=0x000d5dc8 end=0x000d5dec symbol=FUN_000d5dc8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64d); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0000430c();

bool FUN_000d5dc8(u32 param_1,u32 param_2,u32 param_3)
{
  int iVar1;
  
  iVar1 = FUN_0000430c(param_2,param_3);
  return iVar1 < 0;
}
