/* HSTMATCH module=EBOOT.BIN start=0x002161c4 end=0x00216208 symbol=FUN_002161c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a150;
extern void FUN_00000a00();

int FUN_002161c4(int param_1,short param_2)
{
  if ((param_1 != 0) && (DAT_0034a150 = 0, 0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
