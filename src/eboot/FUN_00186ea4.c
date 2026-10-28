/* HSTMATCH module=EBOOT.BIN start=0x00186ea4 end=0x00186ee8 symbol=FUN_00186ea4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00186ea4(int param_1,int param_2,int param_3)
{
  *(u8 *)(param_1 + 0x1250) = 1;
  *(int *)(param_1 + 0x1240) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2;
  *(int *)(param_1 + 0x1244) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_3;
  *(u32 *)(param_1 + 0x124c) = 0;
  *(u32 *)(param_1 + 0x1248) = 0;
}
