/* HSTMATCH module=EBOOT.BIN start=0x001cd55c end=0x001cd584 symbol=FUN_001cd55c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0027bf24();

void FUN_001cd55c(int param_1)
{
  if (*(int *)(param_1 + 0x170) != 0) {
    FUN_0027bf24(*(u32 *)(*(int *)(param_1 + 0x170) + 0x3c));
  }
}
