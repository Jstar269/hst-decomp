/* HSTMATCH module=EBOOT.BIN start=0x00155ea4 end=0x00155ed8 symbol=FUN_00155ea4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308508;
extern u32 * FUN_0014c3f8();

u32 * FUN_00155ea4(u32 *param_1)
{
  FUN_0014c3f8();
  *param_1 = (unsigned int)(&DAT_00308508);
  return param_1;
}
