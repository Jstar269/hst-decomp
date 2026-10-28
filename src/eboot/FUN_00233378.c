/* HSTMATCH module=EBOOT.BIN start=0x00233378 end=0x00233384 symbol=FUN_00233378 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00233378(int *param_1)
{
  return *(u32 *)(*param_1 + 0x1e0);
}
