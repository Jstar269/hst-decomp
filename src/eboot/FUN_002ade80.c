/* HSTMATCH module=EBOOT.BIN start=0x002ade80 end=0x002adec4 symbol=FUN_002ade80 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b5d0;
extern void FUN_00000a00();

int FUN_002ade80(int param_1,short param_2)
{
  if ((param_1 != 0) && (DAT_0034b5d0 = 0, 0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
