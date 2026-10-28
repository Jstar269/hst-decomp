/* HSTMATCH module=EBOOT.BIN start=0x00168388 end=0x001683b0 symbol=FUN_00168388 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00168388(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0;
  param_1[3] = 0x3f000000;
  param_1[4] = 0x40000000;
  return param_1;
}
