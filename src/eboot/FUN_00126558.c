/* HSTMATCH module=EBOOT.BIN start=0x00126558 end=0x001265f8 symbol=FUN_00126558 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308044;
extern void FUN_00000a00();
extern void FUN_002b78e0();
extern void FUN_002b7900();
extern void FUN_002b7e18();

u32 * FUN_00126558(u32 *param_1,short param_2)
{
  int iVar1;
  u32 uVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308044);
    if ((u8 *)param_1[5] != (u8 *)0x0) {
      *(u8 *)param_1[5] = 1;
    }
    iVar1 = param_1[1];
    if (iVar1 >= 1) {
      FUN_002b7e18(param_1[3],0);
      FUN_002b78e0(param_1[1],0);
      FUN_002b7900(param_1[1]);
    }
    uVar2 = param_1[3];
    FUN_002b7e18(uVar2,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
