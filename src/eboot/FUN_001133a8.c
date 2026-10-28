/* HSTMATCH module=EBOOT.BIN start=0x001133a8 end=0x0011343c symbol=FUN_001133a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307d40;
extern u8 DAT_00307d50;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

int * FUN_001133a8(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_00307d40;
    *(u8 **)*param_1 = &DAT_00307d50;
    piVar1 = param_1 + 4;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[4] = (int)&DAT_0030779c;
      FUN_00100b24(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
