/* HSTMATCH module=EBOOT.BIN start=0x00026a94 end=0x00026aac symbol=FUN_00026a94 lang=c99 */
/* Clone of src/sharing_main/FUN_00026abc.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266ac();
extern void FUN_00025f2c();
extern void FUN_00029050();

void FUN_00026a94(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266ac(param_1,param_2,param_3,FUN_00029050,FUN_00025f2c,'\0');
}
