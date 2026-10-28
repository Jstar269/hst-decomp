/* HSTMATCH module=EBOOT.BIN start=0x002a0e58 end=0x002a0e88 symbol=FUN_002a0e58 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc2ac;

u32 * FUN_002a0e58(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_002cc2ac);
  *(u8 *)(param_1 + 1) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  *(u8 *)(param_1 + 0x43) = 0;
  param_1[0x42] = 0x7fffffff;
  return param_1;
}
