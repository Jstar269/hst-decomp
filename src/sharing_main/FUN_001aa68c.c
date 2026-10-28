/* HSTMATCH module=hstp_trans_main.prx start=0x001aa68c end=0x001aa6c8 symbol=FUN_001aa68c lang=c99 */
/* Clone of src/eboot/FUN_0019d1b8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001a871c();

void FUN_001aa68c(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_001a871c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
  }
}
