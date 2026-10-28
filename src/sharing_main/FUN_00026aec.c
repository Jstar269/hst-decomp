/* HSTMATCH module=hstp_trans_main.prx start=0x00026aec end=0x00026b04 symbol=FUN_00026aec lang=c99 */
/* Clone of src/eboot/FUN_00026a94.c (hstclone.py tag u1r2s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266d4();
extern void FUN_00025f3c();
extern void FUN_0002903c();

void FUN_00026aec(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_0002903c,FUN_00025f3c,'\0');
}
