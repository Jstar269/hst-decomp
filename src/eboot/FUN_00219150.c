/* HSTMATCH module=EBOOT.BIN start=0x00219150 end=0x00219184 symbol=FUN_00219150 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003095d8;
extern u32 * FUN_0005a8ec();

u32 * FUN_00219150(u32 *param_1)
{
  FUN_0005a8ec();
  *param_1 = (unsigned int)(&DAT_003095d8);
  return param_1;
}
