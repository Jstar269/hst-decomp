/* HSTMATCH module=EBOOT.BIN start=0x00113314 end=0x001133a8 symbol=FUN_00113314 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307cf0;
extern u8 DAT_00307cfc;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

int * FUN_00113314(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[0x1f] = (int)&DAT_00307cf0;
    *(u8 **)*param_1 = &DAT_00307cfc;
    piVar1 = param_1 + 0x20;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[0x20] = (int)&DAT_0030779c;
      FUN_00100b24(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
