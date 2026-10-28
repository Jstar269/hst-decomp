/* HSTMATCH module=EBOOT.BIN start=0x00221a98 end=0x00221ac0 symbol=FUN_00221a98 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_00221a98(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_001031e8();
  }
}
