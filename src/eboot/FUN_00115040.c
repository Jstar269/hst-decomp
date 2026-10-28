/* HSTMATCH module=EBOOT.BIN start=0x00115040 end=0x00115088 symbol=FUN_00115040 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001142b0();

void FUN_00115040(int param_1,u32 param_2)
{
  *(u8 *)(*(int *)(param_1 + 0x54) + 0x90a) = 1;
  *(u32 *)(param_1 + 0x80) = param_2;
  FUN_001142b0(param_1,5);
  *(u32 *)(param_1 + 0x80) = param_2;
}
