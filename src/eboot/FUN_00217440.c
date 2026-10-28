/* HSTMATCH module=EBOOT.BIN start=0x00217440 end=0x00217474 symbol=FUN_00217440 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003095cc;

u32 * FUN_00217440(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003095cc);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[7] = 0;
  *(u8 *)(param_1 + 8) = 0;
  *(u8 *)((int)param_1 + 0x21) = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1;
}
