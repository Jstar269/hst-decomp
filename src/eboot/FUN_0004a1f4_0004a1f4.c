/* HSTMATCH module=EBOOT.BIN start=0x0004a1f4 end=0x0004a250 symbol=FUN_0004a1f4 lang=c99 */
/* Clone of src/sharing_main/FUN_0004a1c4_0004a1c4.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v16) corrected by hand: reordered the branch arms and kept cleanup inside the nonnull case; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00311170;
extern void FUN_000009e4();
extern void FUN_0004fe04();

void FUN_0004a1f4(int param_1)
{
  if (*(int *)(param_1 + 0x20) >= 0) {
    FUN_0004fe04((int)&DAT_00311170,*(int *)((int)param_1 + 32));
    *(u32 *)(param_1 + 0x20) = 0xffffffff;
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_000009e4(*(int *)((int)param_1 + 28));
      *(u32 *)(param_1 + 0x1c) = 0;
    }
  }
}
