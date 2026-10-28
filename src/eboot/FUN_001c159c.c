/* HSTMATCH module=EBOOT.BIN start=0x001c159c end=0x001c15bc symbol=FUN_001c159c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c159c(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  *(u32 *)(param_1 + 0x38) = param_2;
  *(u32 *)(param_1 + 0x3c) = param_3;
  *(u32 *)(param_1 + 0x24) = param_4;
  *(u32 *)(param_1 + 0x28) = param_5;
  *(u32 *)(param_1 + 0x2c) = param_6;
  *(u32 *)(param_1 + 0x30) = param_7;
  *(u32 *)(param_1 + 0x34) = param_8;
}
