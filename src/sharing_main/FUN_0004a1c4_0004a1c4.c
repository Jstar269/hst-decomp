/* HSTMATCH module=hstp_trans_main.prx start=0x0004a1c4 end=0x0004a220 symbol=FUN_0004a1c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v16) corrected by hand: reordered the branch arms and kept cleanup inside the nonnull case; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003ba4b0;
extern void FUN_000009e4();
extern void FUN_000506b8();

void FUN_0004a1c4(int param_1)
{
  if (*(int *)(param_1 + 0x20) >= 0) {
    FUN_000506b8((int)&DAT_003ba4b0,*(int *)((int)param_1 + 32));
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
