/* HSTMATCH module=EBOOT.BIN start=0x000d4d34 end=0x000d4ddc symbol=FUN_000d4d34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030744c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int FUN_00053718();
extern int FUN_00055e48();
extern void FUN_00056cb0();

u32 * FUN_000d4d34(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030744c);
    if (param_1[0xf] != 0) {
      FUN_00053718(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    iVar1 = param_1[0x10];
    if (iVar1 != 0) {
      FUN_00055e48(iVar1,1);
      param_1[0x10] = 0;
    }
    FUN_00000788(param_1 + 0x14,FUN_00056cb0,0x1b0,4);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
