/* HSTMATCH module=EBOOT.BIN start=0x00117128 end=0x00117154 symbol=FUN_00117128 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00117128(int param_1)
{
  *(u8 *)(param_1 + 0x4c) = 0;
  *(u32 *)(param_1 + 0x50) = 0;
  *(u8 *)(param_1 + 0x54) = 0;
  *(u32 *)(param_1 + 0x58) = 0;
  *(u32 *)(param_1 + 0x5c) = 0xffffffff;
  *(u32 *)(param_1 + 0x60) = 0xffffffff;
  *(u32 *)(param_1 + 100) = 0xffffffff;
  *(u32 *)(param_1 + 0x6c) = 0xffffffff;
  *(u8 *)(param_1 + 0x40) = 0;
}
