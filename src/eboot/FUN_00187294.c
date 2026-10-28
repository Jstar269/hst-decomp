/* HSTMATCH module=EBOOT.BIN start=0x00187294 end=0x001872a0 symbol=FUN_00187294 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00187294(int param_1,u8 param_2)
{
  *(u8 *)(*(int *)(param_1 + 0x1180) + 0x12d) = param_2;
}
