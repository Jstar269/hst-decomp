/* HSTMATCH module=EBOOT.BIN start=0x00179178 end=0x00179190 symbol=FUN_00179178 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00179178(int param_1,int param_2)
{
  return *(u32 *)(**(int **)(param_1 + 0x1d4) + param_2 * 4);
}
