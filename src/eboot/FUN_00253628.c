/* HSTMATCH module=EBOOT.BIN start=0x00253628 end=0x00253630 symbol=FUN_00253628 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00253628(int param_1)
{
  return *(u32 *)(param_1 + 0x38);
}
