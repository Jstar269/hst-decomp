/* HSTMATCH module=EBOOT.BIN start=0x000950e0 end=0x00095104 symbol=FUN_000950e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_000950e0(int param_1,int param_2)
{
  bool bVar1;
  
  if (*(u32 *)(param_1 + 0x1b0) < 3) {
    bVar1 = *(short *)(param_1 + 0x1b8) == param_2;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}
