/* HSTMATCH module=EBOOT.BIN start=0x0008c230 end=0x0008c248 symbol=FUN_0008c230 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0008c230(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
