/* HSTMATCH module=hstp_trans_main.prx start=0x00026a5c end=0x00026a74 symbol=FUN_00026a5c lang=c99 */
/* Clone of src/eboot/FUN_00026a34.c (hstclone.py tag u1r2s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266d4();
extern void FUN_00027544();
extern void FUN_000291ec();

void FUN_00026a5c(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_000291ec,FUN_00027544,'\x01');
}
