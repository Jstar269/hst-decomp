/* HSTMATCH module=EBOOT.BIN start=0x0027e71c end=0x0027e748 symbol=FUN_0027e71c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c7c;

u32 * FUN_0027e71c(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309c7c);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}
