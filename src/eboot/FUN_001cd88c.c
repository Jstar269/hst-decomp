/* HSTMATCH module=EBOOT.BIN start=0x001cd88c end=0x001cd8cc symbol=FUN_001cd88c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ce864();

void FUN_001cd88c(int param_1,u32 param_2,int param_3)
{
  *(u32 *)(param_1 + 0x10) = param_2;
  if (param_3 < 1) {
    FUN_001ce864();
    *(u32 *)(param_1 + 8) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0xc) = param_3;
  }
}
