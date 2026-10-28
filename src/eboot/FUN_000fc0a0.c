/* HSTMATCH module=EBOOT.BIN start=0x000fc0a0 end=0x000fc0e0 symbol=FUN_000fc0a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b6c;

u32 * FUN_000fc0a0(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00307b6c);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[8] = 0x47c35000;
  *(u8 *)(param_1 + 9) = 0;
  return param_1;
}
