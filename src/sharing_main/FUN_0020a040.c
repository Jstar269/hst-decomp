/* HSTMATCH module=hstp_trans_main.prx start=0x0020a040 end=0x0020a080 symbol=FUN_0020a040 lang=c99 */
/* Clone of src/eboot/FUN_001cd88c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0020a090();

void FUN_0020a040(int param_1,u32 param_2,int param_3)
{
  *(u32 *)(param_1 + 0x10) = param_2;
  if (param_3 < 1) {
    FUN_0020a090();
    *(u32 *)(param_1 + 8) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0xc) = param_3;
  }
}
