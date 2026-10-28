/* HSTMATCH module=EBOOT.BIN start=0x001cd594 end=0x001cd5a0 symbol=FUN_001cd594 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001cd594(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x170) + 0x3c);
}
