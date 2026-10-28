/* HSTMATCH module=EBOOT.BIN start=0x002af0cc end=0x002af0d4 symbol=FUN_002af0cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002af0cc(int param_1)
{
  return *(u32 *)(param_1 + 4);
}
