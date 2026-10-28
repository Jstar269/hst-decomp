/* HSTMATCH module=EBOOT.BIN start=0x00186ee8 end=0x00186f18 symbol=FUN_00186ee8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00102c54();

void FUN_00186ee8(int param_1,int param_2)
{
  *(u8 *)(param_1 + 0x1250) = 0;
  *(float *)(*(int *)(param_1 + 0x28) + 0x60) =
       (float)(*(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2);
  FUN_00102c54(*(u32 *)(param_1 + 0x28));
}
