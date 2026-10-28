/* HSTMATCH module=EBOOT.BIN start=0x000fb874 end=0x000fb880 symbol=FUN_000fb874 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000fb874(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x98);
}
