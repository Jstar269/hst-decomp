/* HSTMATCH module=EBOOT.BIN start=0x00221590 end=0x002215b8 symbol=FUN_00221590 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_00221590(int param_1)
{
  if (*(u8 *)(param_1 + 0x58) == '\0') {
    FUN_001031e8();
  }
}
