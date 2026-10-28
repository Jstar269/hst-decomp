/* HSTMATCH module=EBOOT.BIN start=0x001d6bb0 end=0x001d6bc8 symbol=FUN_001d6bb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_001d6bb0(u32 *param_1)
{
  *param_1 = 0;
  *(u16 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *(u8 *)(param_1 + 3) = 0;
  return param_1;
}
