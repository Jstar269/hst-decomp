/* HSTMATCH module=EBOOT.BIN start=0x001bace8 end=0x001bad34 symbol=FUN_001bace8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00204c80();

void FUN_001bace8(int param_1,int param_2)
{
  FUN_00204c80(*(u32 *)(*(int *)(param_1 + 4) + param_2 * 4));
  *(u8 *)(param_2 + param_1 + 0x10) = 0;
  *(u8 *)(param_2 + param_1 + 0x14) = 0;
}
