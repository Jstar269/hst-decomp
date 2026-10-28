/* HSTMATCH module=hstp_trans_main.prx start=0x00026b04 end=0x00026b1c symbol=FUN_00026b04 lang=c99 */
/* Clone of src/eboot/FUN_00026a4c.c (hstclone.py tag u1r2s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266d4();
extern void FUN_00027b8c();
extern void FUN_00029300();

void FUN_00026b04(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_00029300,FUN_00027b8c,'\x01');
}
