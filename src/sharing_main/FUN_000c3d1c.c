/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d1c end=0x000c3d50 symbol=FUN_000c3d1c lang=c99 */
/* Clone of src/eboot/FUN_000c067c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00104f10();

void FUN_000c3d1c(int param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  
  uVar1 = FUN_00104f10(*(u32 *)(param_1 + 0x18),param_2,*param_3,0);
  *param_3 = uVar1;
}
