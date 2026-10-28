/* HSTMATCH module=EBOOT.BIN start=0x002a4488 end=0x002a44f0 symbol=FUN_002a4488 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;
extern void FUN_002a2488();

void FUN_002a4488(int param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(DAT_003415a8 + 0x86d10);
  if (((uVar1 & 1) == 0) &&
     (*(u32 *)(DAT_003415a8 + 0x86d10) = uVar1 | 1, *(int *)(param_1 + 0x1b0) != 5)) {
    *(u32 *)(param_1 + 0x1c0) = *(u32 *)(param_1 + 0x1b8);
    *(u32 *)(param_1 + 0x1b8) = 0;
    *(u32 *)(param_1 + 0x1bc) = 0;
    FUN_002a2488(param_1,1);
  }
}
