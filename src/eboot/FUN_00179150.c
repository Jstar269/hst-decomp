/* HSTMATCH module=EBOOT.BIN start=0x00179150 end=0x0017916c symbol=FUN_00179150 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00179150(int param_1,int param_2)
{
  return **(u32 **)(**(int **)(param_1 + 0x1d4) + param_2 * 4);
}
