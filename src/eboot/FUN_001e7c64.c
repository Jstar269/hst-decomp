/* HSTMATCH module=EBOOT.BIN start=0x001e7c64 end=0x001e7ca8 symbol=FUN_001e7c64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_001e7c64(int param_1,int param_2)
{
  FUN_00103628(*(u32 *)(param_1 + 0x250c));
  if (param_2 == 0) {
    *(u32 *)(param_1 + 0x2528) = 0x3c;
  }
  else {
    *(u32 *)(param_1 + 0x2528) = 0;
  }
}
