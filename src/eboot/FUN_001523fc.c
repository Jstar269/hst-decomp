/* HSTMATCH module=EBOOT.BIN start=0x001523fc end=0x00152484 symbol=FUN_001523fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030840c;
extern u8 DAT_00308c20;
extern void FUN_000009e4();
extern void FUN_00000a00();

u32 * FUN_001523fc(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308c20);
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      param_1[4] = 0;
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
