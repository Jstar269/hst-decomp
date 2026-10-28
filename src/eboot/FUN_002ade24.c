/* HSTMATCH module=EBOOT.BIN start=0x002ade24 end=0x002ade48 symbol=FUN_002ade24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0001100c();

bool FUN_002ade24(u32 param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = FUN_0001100c(param_1,param_2,0x10);
  return iVar1 == 0;
}
