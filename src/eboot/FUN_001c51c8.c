/* HSTMATCH module=EBOOT.BIN start=0x001c51c8 end=0x001c51d4 symbol=FUN_001c51c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c51c8(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0xc4) = param_2;
  *(u32 *)(param_1 + 200) = 0;
}
