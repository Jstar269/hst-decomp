/* HSTMATCH module=EBOOT.BIN start=0x00115e60 end=0x00115f24 symbol=FUN_00115e60 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307f04;
extern u8 DAT_00307f18;
extern u8 DAT_00307f60;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern int * FUN_00107514();

int * FUN_00115e60(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_00307f04;
    *(u8 **)*param_1 = &DAT_00307f18;
    *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
    if ((param_2 != 0) && (param_1 + 0x1c != (int *)0x0)) {
      piVar1 = param_1 + 100;
      param_1[0x1c] = (int)&DAT_00307f60;
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_00107514(piVar1,0);
      }
      if (param_1 + 0x1c != (int *)0x0) {
        param_1[0x1c] = (int)&DAT_0030779c;
        FUN_00100b24(param_1 + 0x1c,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
