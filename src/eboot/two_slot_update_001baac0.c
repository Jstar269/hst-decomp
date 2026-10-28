/* HSTMATCH module=EBOOT.BIN start=0x001baac0 end=0x001bab98 symbol=FUN_001baac0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the flag byte is set with `if (b) 1 else 0` (truthy test; the `== 0` order puts the store in the other branch-likely slot); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 FUN_001baf80();
extern void FUN_00206290();

void FUN_001baac0(int param_1,int *param_2)
{
  u8 uVar1;
  
  if (*(u8 *)(*param_2 + 0x60) != '\0') {
    uVar1 = FUN_001baf80(*(u32 *)(*(int *)(*(int *)(param_1 + 4) + 8) + 4));
    FUN_00206290(*(u32 *)(*(int *)(param_1 + 4) + 8),uVar1,*(u32 *)(*param_2 + 100));
    *(u8 *)(param_1 + 0x12) = 1;
    *(u8 *)(param_1 + 0x16) = 1;
    if (*(u8 *)(*param_2 + 0x6a)) {
      *(u8 *)(param_1 + 0x1a) = 1;
    }
    else {
      *(u8 *)(param_1 + 0x1a) = 0;
    }
  }
  if (*(u8 *)(*param_2 + 0x90) != '\0') {
    uVar1 = FUN_001baf80(*(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 4));
    FUN_00206290(*(u32 *)(*(int *)(param_1 + 4) + 0xc),uVar1,*(u32 *)(*param_2 + 0x94)
                );
    *(u8 *)(param_1 + 0x13) = 1;
    *(u8 *)(param_1 + 0x17) = 1;
    if (*(u8 *)(*param_2 + 0x9a)) {
      *(u8 *)(param_1 + 0x1b) = 1;
    }
    else {
      *(u8 *)(param_1 + 0x1b) = 0;
    }
  }
}
