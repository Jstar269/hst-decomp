/* HSTMATCH module=EBOOT.BIN start=0x000c067c end=0x000c06b0 symbol=FUN_000c067c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000ff678();

void FUN_000c067c(int param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  
  uVar1 = FUN_000ff678(*(u32 *)(param_1 + 0x18),param_2,*param_3,0);
  *param_3 = uVar1;
}
