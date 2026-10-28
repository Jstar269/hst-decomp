/* HSTMATCH module=EBOOT.BIN start=0x00224830 end=0x00224860 symbol=FUN_00224830 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_00224830(int param_1)
{
  FUN_00103628(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
}
