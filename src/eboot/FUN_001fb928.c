/* HSTMATCH module=EBOOT.BIN start=0x001fb928 end=0x001fb968 symbol=FUN_001fb928 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001fb978();

void FUN_001fb928(int param_1,u32 param_2,int param_3)
{
  *(u32 *)(param_1 + 0x10) = param_2;
  if (param_3 < 1) {
    FUN_001fb978();
    *(u32 *)(param_1 + 8) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0xc) = param_3;
  }
}
