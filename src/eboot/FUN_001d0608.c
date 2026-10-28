/* HSTMATCH module=EBOOT.BIN start=0x001d0608 end=0x001d0610 symbol=FUN_001d0608 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_001d0608(int param_1)
{
  return *(u16 *)(param_1 + 6);
}
