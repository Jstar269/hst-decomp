/* HSTMATCH module=EBOOT.BIN start=0x00054010 end=0x00054058 symbol=FUN_00054010 lang=c99 */
/* Clone of src/sharing_main/FUN_00054b5c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0002e7d0();
extern void FUN_00054058();

void FUN_00054010(int param_1,u32 param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_0002e7d0(*(int *)(param_1 + 8) + 0x10);
  FUN_00054058(param_1,param_2,*puVar1);
}
