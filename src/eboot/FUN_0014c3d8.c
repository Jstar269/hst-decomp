/* HSTMATCH module=EBOOT.BIN start=0x0014c3d8 end=0x0014c3f8 symbol=FUN_0014c3d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0022a970();

u32 FUN_0014c3d8(u32 param_1,int param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_0022a970(param_2 + 0xf0);
  return *puVar1;
}
