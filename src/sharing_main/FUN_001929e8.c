/* HSTMATCH module=hstp_trans_main.prx start=0x001929e8 end=0x00192ac4 symbol=FUN_001929e8 lang=c99 */
/* Clone of src/eboot/FUN_0018629c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00191248();
extern void FUN_0019192c();
extern void FUN_001934b0();

void FUN_001929e8(int param_1,u32 param_2,u32 param_3,u32 param_4,int param_5, int param_6,u32 param_7,u32 param_8)
{
  u32 local_4;
  u32 local_8;
  
  if (param_6 != 0) {
    FUN_001934b0(param_1,param_3,param_4,param_5);
  }
  local_4 = 0;
  local_8 = 0;
  FUN_00191248(param_1,&local_4,&local_8,param_2);
  FUN_0019192c(param_1,param_2,param_3,param_4,param_5,param_7,param_6,local_8,param_8);
  *(float *)(*(int *)(param_1 + 0x2860) + 0xe0) = (float)param_5;
}
