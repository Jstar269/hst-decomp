/* HSTMATCH module=EBOOT.BIN start=0x00026a1c end=0x00026a34 symbol=FUN_00026a1c lang=c99 */
/* Clone of src/sharing_main/FUN_00026a74.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266ac();
extern void FUN_00026f34();
extern void FUN_000290ec();

void FUN_00026a1c(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266ac(param_1,param_2,param_3,FUN_000290ec,FUN_00026f34,'\x01');
}
