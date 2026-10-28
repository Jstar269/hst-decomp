/* HSTMATCH module=EBOOT.BIN start=0x002a4ee4 end=0x002a4f18 symbol=FUN_002a4ee4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010abe8();

void FUN_002a4ee4(char *param_1)
{
  if (*(int *)(param_1 + 0x5d0) == 2) {
    FUN_0010abe8(param_1 + 0x40,(u32 *)(param_1 + 0x5d4));
  }
}
