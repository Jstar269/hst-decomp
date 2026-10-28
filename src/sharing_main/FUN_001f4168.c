/* HSTMATCH module=hstp_trans_main.prx start=0x001f4168 end=0x001f41d4 symbol=FUN_001f4168 lang=c99 */
/* Clone of src/eboot/FUN_001e5f50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f443c();

void FUN_001f4168(int param_1,u32 param_2,u32 param_3,int param_4)
{
  FUN_001f08e8(param_1);
  FUN_00108f54(*(int *)(param_1 + 0x1958),0);
  FUN_001f443c(param_1,param_2,param_3,param_4,'\0');
}
