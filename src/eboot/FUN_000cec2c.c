/* HSTMATCH module=EBOOT.BIN start=0x000cec2c end=0x000cec58 symbol=FUN_000cec2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005f1e8();

void FUN_000cec2c(int param_1)
{
  if (*(u8 *)(param_1 + 0x3c) != '\0') {
    FUN_0005f1e8(param_1 + 0x40,0);
  }
}
