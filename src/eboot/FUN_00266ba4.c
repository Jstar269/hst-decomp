/* HSTMATCH module=EBOOT.BIN start=0x00266ba4 end=0x00266c48 symbol=FUN_00266ba4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309afc;
extern void FUN_00000a00();
extern int * FUN_000e88e4();
extern u32 * FUN_0028686c();

u32 * FUN_00266ba4(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309afc);
    if ((char *)param_1 + 0x80 != (char *)0) {
      piVar1 = (int *)(param_1 + 0x41);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000e88e4(piVar1,0);
      }
      piVar1 = (int *)(param_1 + 0x3c);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000e88e4(piVar1,0);
      }
    }
    FUN_0028686c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
