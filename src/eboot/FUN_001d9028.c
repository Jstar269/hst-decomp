/* HSTMATCH module=EBOOT.BIN start=0x001d9028 end=0x001d9038 symbol=FUN_001d9028 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d9028(int param_1)
{
  *(u32 *)(param_1 + 0x520) = 0;
  *(u32 *)(param_1 + 0x51c) = 6;
}
