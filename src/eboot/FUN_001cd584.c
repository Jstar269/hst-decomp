/* HSTMATCH module=EBOOT.BIN start=0x001cd584 end=0x001cd58c symbol=FUN_001cd584 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001cd584(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x168) = param_2;
}
