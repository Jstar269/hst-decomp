/* HSTMATCH module=EBOOT.BIN start=0x002a0e08 end=0x002a0e34 symbol=FUN_002a0e08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010d4a8();

void FUN_002a0e08(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x14c) = param_2;
  if (*(u8 *)(param_1 + 0x14c) == '\0') {
    FUN_0010d4a8();
  }
}
