/* HSTMATCH module=hstp_trans_main.prx start=0x00002bfc end=0x00002c34 symbol=FUN_00002bfc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00002c34();

u32 FUN_00002bfc(u32 param_1)
{
  u32 *puVar1;
  u32 uVar2;
  
  puVar1 = (u32 *)FUN_00002c34();
  uVar2 = *puVar1;
  puVar1 = (u32 *)FUN_00002c34(param_1);
  *puVar1 = 0;
  return uVar2;
}
