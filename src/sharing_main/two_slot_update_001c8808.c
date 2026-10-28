/* HSTMATCH module=hstp_trans_main.prx start=0x001c8808 end=0x001c88e0 symbol=FUN_001c8808 lang=c99 */
/* Clone of src/eboot/two_slot_update_001baac0.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the flag u8 is set with `if (b) 1 else 0` (truthy test; the `== 0` order puts the store in the other branch-likely slot); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 FUN_001c8cc8();
extern void FUN_00214af8();

void FUN_001c8808(int param_1,int *param_2)
{
  u8 uVar1;
  
  if (*(u8 *)(*param_2 + 0x60) != '\0') {
    uVar1 = FUN_001c8cc8(*(u32 *)(*(int *)(*(int *)(param_1 + 4) + 8) + 4));
    FUN_00214af8(*(u32 *)(*(int *)(param_1 + 4) + 8),uVar1,*(u32 *)(*param_2 + 100));
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
    uVar1 = FUN_001c8cc8(*(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 4));
    FUN_00214af8(*(u32 *)(*(int *)(param_1 + 4) + 0xc),uVar1,*(u32 *)(*param_2 + 0x94)
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
