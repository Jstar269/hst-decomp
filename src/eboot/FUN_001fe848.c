/* HSTMATCH module=EBOOT.BIN start=0x001fe848 end=0x001fe888 symbol=FUN_001fe848 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001fe848(int param_1,int param_2,int param_3)
{
  int *piVar1;
  
  if (param_3 < 10) {
    piVar1 = (int *)(param_1 + param_3 * 0x20);
    do {
      if (param_2 == *piVar1) {
        return 1;
      }
      param_3 = param_3 + 1;
      piVar1 = piVar1 + 8;
    } while (param_3 < 10);
  }
  return 0;
}
