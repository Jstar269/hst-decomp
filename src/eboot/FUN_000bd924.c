/* HSTMATCH module=EBOOT.BIN start=0x000bd924 end=0x000bd92c symbol=FUN_000bd924 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000bd924(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x284) = param_2;
}
