/* HSTMATCH module=EBOOT.BIN start=0x0021f59c end=0x0021f5c4 symbol=FUN_0021f59c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_0021f59c(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_001031e8();
  }
}
