/* HSTMATCH module=EBOOT.BIN start=0x001a41d0 end=0x001a4224 symbol=FUN_001a41d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0016b998();

void FUN_001a41d0(int param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_0016b998(**(u32 **)(*(int *)(param_1 + 0x378) + *(int *)(param_1 + 0x2c4) * 4));
  }
  else {
    *(u32 *)(param_1 + 0x2c0) = *(u32 *)(param_1 + 0x2cc);
    *(u32 *)(param_1 + 0x2c4) = *(u32 *)(param_1 + 0x2d0);
    *(u32 *)(param_1 + 0x2c8) = *(u32 *)(param_1 + 0x2d4);
  }
}
