/* HSTMATCH module=EBOOT.BIN start=0x001fb4fc end=0x001fb524 symbol=FUN_001fb4fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003418bc;

bool FUN_001fb4fc(int param_1)
{
  return (&DAT_003418bc)[*(int *)(param_1 + 0x3cc) * 0x120] != '\0';
}
