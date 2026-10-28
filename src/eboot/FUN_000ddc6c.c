/* HSTMATCH module=EBOOT.BIN start=0x000ddc6c end=0x000ddca8 symbol=FUN_000ddc6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;

void FUN_000ddc6c(int param_1)
{
  *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x54) =
       *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x54) + *(int *)(param_1 + 0xc4);
  *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x58) =
       *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x58) + *(int *)(param_1 + 200);
}
