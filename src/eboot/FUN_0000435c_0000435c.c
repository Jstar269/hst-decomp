/* HSTMATCH module=EBOOT.BIN start=0x0000435c end=0x000043b4 symbol=FUN_0000435c lang=c99 */
/* Clone of src/sharing_main/FUN_0000435c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003100();
extern void FUN_00003de8();

void FUN_0000435c(u32 param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  
  uVar1 = FUN_00003100(param_1);
  FUN_00003de8(param_1,0,uVar1,param_2,param_3,0);
}
