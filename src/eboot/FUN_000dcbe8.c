/* HSTMATCH module=EBOOT.BIN start=0x000dcbe8 end=0x000dcc04 symbol=FUN_000dcbe8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000dcbe8(int param_1)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u8 *)(param_1 + 0x66) = 1;
  }
}
