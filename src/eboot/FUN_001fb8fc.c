/* HSTMATCH module=EBOOT.BIN start=0x001fb8fc end=0x001fb928 symbol=FUN_001fb8fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309510;

u32 * FUN_001fb8fc(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309510);
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}
