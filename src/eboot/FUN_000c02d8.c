/* HSTMATCH module=EBOOT.BIN start=0x000c02d8 end=0x000c0308 symbol=FUN_000c02d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073fc;

u32 * FUN_000c02d8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003073fc);
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}
