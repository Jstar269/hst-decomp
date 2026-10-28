/* HSTMATCH module=EBOOT.BIN start=0x0010c17c end=0x0010c228 symbol=FUN_0010c17c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the virtual-base constructor argument is the base sub-object pointer plus 0x120 (not this+400), and the vbase back-pointer store is the pointer difference (this+0x70)-*this; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d9210;
extern u8 DAT_00307f04;
extern u8 DAT_00307f18;
extern u8 DAT_00307f60;
extern u32 * FUN_00103d6c();
extern u32 * FUN_00103d80();
extern void FUN_0010b308();
extern void FUN_0010c2b4();

int * FUN_0010c17c(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = param_1 + 0x1c;
    *param_1 = (int)piVar1;
    FUN_00103d80(piVar1,&DAT_002d9210);
    *piVar1 = (int)&DAT_00307f60;
    FUN_00103d6c(piVar1 + 0x48);
    FUN_0010b308(piVar1);
  }
  param_1[1] = (int)&DAT_00307f04;
  *(u8 **)*param_1 = &DAT_00307f18;
  *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
  param_1[2] = 0;
  param_1[3] = 0;
  *(u8 *)(param_1 + 0x1b) = 0;
  *(u8 *)((int)param_1 + 0x6d) = 0;
  FUN_0010c2b4(param_1);
  return param_1;
}
