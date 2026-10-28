/* HSTMATCH module=EBOOT.BIN start=0x00003268 end=0x000032ac symbol=FUN_00003268 lang=c99 */
/* Clone of src/sharing_main/FUN_00003268.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003100();
extern void FUN_000032ac();

void FUN_00003268(u32 param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = FUN_00003100(param_1);
  FUN_000032ac(param_1,0,uVar1,param_2);
}
