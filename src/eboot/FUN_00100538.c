/* HSTMATCH module=EBOOT.BIN start=0x00100538 end=0x00100584 symbol=FUN_00100538 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00038230();

void FUN_00100538(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  u32 uVar1;
  
  uVar1 = FUN_00038230(*(u32 *)(param_1 + 0x28),param_3,param_5,param_7,param_2,param_4,
                       param_6);
  *(u32 *)(param_1 + 0x28) = uVar1;
}
