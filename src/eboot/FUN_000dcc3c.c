/* HSTMATCH module=EBOOT.BIN start=0x000dcc3c end=0x000dcc54 symbol=FUN_000dcc3c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000dcc3c(int param_1,u8 param_2)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u8 *)(param_1 + 0x70) = param_2;
  }
}
