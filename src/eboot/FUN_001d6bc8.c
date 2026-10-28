/* HSTMATCH module=EBOOT.BIN start=0x001d6bc8 end=0x001d6bf0 symbol=FUN_001d6bc8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c94;
extern u8 DAT_00309ca0;

u32 * FUN_001d6bc8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309ca0);
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = (unsigned int)(&DAT_00309c94);
  return param_1;
}
