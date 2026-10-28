/* HSTMATCH module=EBOOT.BIN start=0x000b5d60 end=0x000b5d78 symbol=FUN_000b5d60 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_000b5d60(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}
