/* HSTMATCH module=EBOOT.BIN start=0x002ade6c end=0x002ade80 symbol=FUN_002ade6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b5d0;

u32 * FUN_002ade6c(u32 *param_1)
{
  *param_1 = 0;
  DAT_0034b5d0 = (unsigned int)(param_1);
  return param_1;
}
