/* HSTMATCH module=EBOOT.BIN start=0x00114fc0 end=0x00114fd4 symbol=FUN_00114fc0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00114fc0(int param_1,int param_2)
{
  return *(u32 *)(*(int *)(param_1 + 0x10) + param_2 * 4);
}
