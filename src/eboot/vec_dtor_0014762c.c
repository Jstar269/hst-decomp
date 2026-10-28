/* HSTMATCH module=EBOOT.BIN start=0x0014762c end=0x00147724 symbol=FUN_0014762c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: the three calls to the delete function (0xa00) take their arguments (element field +8, the buffer pointer *param_1, and the object itself); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_00147724();
extern int FUN_0014772c();

int * FUN_0014762c(int *param_1,short param_2)
{
  u32 *puVar1;
  u32 *puVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (u32 *)(*param_1 + param_1[4] * 0x28);
    puVar2 = puVar1 + param_1[1] * 10;
    if (puVar1 < puVar2) {
      do {
        puVar2 = puVar2 + -10;
        if (((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) && ((*puVar2 & 1) != 0)) {
          FUN_00000a00((void *)puVar2[2]);
        }
      } while (puVar1 < puVar2);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if ((param_1 != (int *)0x0) && (FUN_0014772c((int)param_1), *param_1 != 0)) {
      FUN_00147724((int)param_1);
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
