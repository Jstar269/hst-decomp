/* HSTMATCH module=EBOOT.BIN start=0x0025346c end=0x002534b4 symbol=FUN_0025346c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the nested mode and byte arms and made the byte unsigned; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001d9cfc();

void FUN_0025346c(int param_1,int param_2)
{
  u32 uVar1;
  
  if (param_2 != 0) {
    if (*(unsigned char *)(param_1 + 0x34) != 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  uVar1 = FUN_001d9cfc(param_1 + 0x3c,uVar1);
  *(u32 *)(param_1 + 0x38) = uVar1;
}
