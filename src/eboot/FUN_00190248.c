/* HSTMATCH module=EBOOT.BIN start=0x00190248 end=0x00190250 symbol=FUN_00190248 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00190248(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x30) = param_2;
}
