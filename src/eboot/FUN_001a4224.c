/* HSTMATCH module=EBOOT.BIN start=0x001a4224 end=0x001a4278 symbol=FUN_001a4224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0016b998();

void FUN_001a4224(int param_1)
{
  FUN_0016b998(**(u32 **)(*(int *)(param_1 + 0x378) + *(int *)(param_1 + 0x2c4) * 4));
  *(u32 *)(param_1 + 0x2cc) = *(u32 *)(param_1 + 0x2c0);
  *(u32 *)(param_1 + 0x2d0) = *(u32 *)(param_1 + 0x2c4);
  *(u32 *)(param_1 + 0x2d4) = *(u32 *)(param_1 + 0x2c8);
}
