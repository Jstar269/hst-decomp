/* HSTMATCH module=EBOOT.BIN start=0x002a44f0 end=0x002a4558 symbol=FUN_002a44f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;
extern void FUN_002a2488();

void FUN_002a44f0(int param_1,u32 param_2,u32 param_3,int *param_4,u32 param_5, u32 param_6,u32 param_7,u32 param_8)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)(DAT_003415a8 + 0x86d10);
  if (((*puVar1 & 2) == 0) && (*puVar1 = *puVar1 | 2, *(int *)(param_1 + 0x1b0) != 5)) {
    *(u32 *)(param_1 + 0x1c0) = *(u32 *)(param_1 + 0x1b8);
    *(u32 *)(param_1 + 0x1b8) = 1;
    *(u32 *)(param_1 + 0x1bc) = 0;
    FUN_002a2488(param_1,1,puVar1,param_4,param_5,param_6,param_7,param_8);
  }
}
