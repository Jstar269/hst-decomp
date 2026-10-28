/* HSTMATCH module=EBOOT.BIN start=0x00220ed8 end=0x00220f00 symbol=FUN_00220ed8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_00220ed8(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_001031e8();
  }
}
