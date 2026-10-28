/* HSTMATCH module=EBOOT.BIN start=0x000ce8e8 end=0x000ce90c symbol=FUN_000ce8e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030753c;
extern u8 DAT_00307550;

u32 * FUN_000ce8e8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_0030753c);
  param_1[1] = 0;
  *param_1 = (unsigned int)(&DAT_00307550);
  return param_1;
}
