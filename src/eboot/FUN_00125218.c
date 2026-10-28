/* HSTMATCH module=EBOOT.BIN start=0x00125218 end=0x00125220 symbol=FUN_00125218 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00125218(int param_1)
{
  return *(u32 *)(param_1 + 0x3c);
}
