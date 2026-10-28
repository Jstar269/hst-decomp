/* HSTMATCH module=EBOOT.BIN start=0x00125228 end=0x00125230 symbol=FUN_00125228 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00125228(int param_1)
{
  return *(u32 *)(param_1 + 0x44);
}
