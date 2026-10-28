/* HSTMATCH module=EBOOT.BIN start=0x00217588 end=0x002175a4 symbol=FUN_00217588 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00217588(int param_1,int param_2)
{
  *(u8 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x1c) = -param_2 * *(int *)(param_1 + 8);
}
