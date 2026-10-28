/* HSTMATCH module=EBOOT.BIN start=0x002b6ef8 end=0x002b6f24 symbol=FUN_002b6ef8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309ff0;

u32 * FUN_002b6ef8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309ff0);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}
