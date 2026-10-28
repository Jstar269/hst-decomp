/* HSTMATCH module=EBOOT.BIN start=0x001ce020 end=0x001ce028 symbol=FUN_001ce020 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001ce020(int param_1)
{
  return *(u32 *)(param_1 + 0x34);
}
