/* HSTMATCH module=EBOOT.BIN start=0x001baf24 end=0x001baf40 symbol=FUN_001baf24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001baf24(int param_1,int param_2)
{
  return *(u8 *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x75);
}
