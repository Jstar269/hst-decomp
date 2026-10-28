/* HSTMATCH module=EBOOT.BIN start=0x002666fc end=0x00266714 symbol=FUN_002666fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002666fc(int param_1,u8 param_2)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(u8 *)(*(int *)(param_1 + 0x70) + 0xc0) = param_2;
  }
}
