/* HSTMATCH module=EBOOT.BIN start=0x0014c3f8 end=0x0014c40c symbol=FUN_0014c3f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003083e4;

u32 * FUN_0014c3f8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003083e4);
  return param_1;
}
