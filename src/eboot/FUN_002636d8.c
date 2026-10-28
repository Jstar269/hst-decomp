/* HSTMATCH module=EBOOT.BIN start=0x002636d8 end=0x0026370c symbol=FUN_002636d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309a88;
extern u32 * FUN_00067498();

u32 * FUN_002636d8(u32 *param_1)
{
  FUN_00067498();
  *param_1 = (unsigned int)(&DAT_00309a88);
  return param_1;
}
