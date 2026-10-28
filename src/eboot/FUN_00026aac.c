/* HSTMATCH module=EBOOT.BIN start=0x00026aac end=0x00026ac4 symbol=FUN_00026aac lang=c99 */
/* Clone of src/sharing_main/FUN_00026abc.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266ac();
extern void FUN_00025f20();
extern void FUN_00029208();

void FUN_00026aac(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266ac(param_1,param_2,param_3,FUN_00029208,FUN_00025f20,'\0');
}
