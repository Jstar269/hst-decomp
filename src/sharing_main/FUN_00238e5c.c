/* HSTMATCH module=hstp_trans_main.prx start=0x00238e5c end=0x00238ed0 symbol=FUN_00238e5c lang=c99 */
/* Clone of src/eboot/FUN_002298e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_002392d4();

void FUN_00238e5c(int *param_1,char *param_2,u32 *param_3)
{
  u32 *puVar1;
  
  puVar1 = FUN_002392d4(param_2,param_3,*(u32 **)(param_2 + 4),(u32 *)(param_2 + 4));
  if ((puVar1 == (u32 *)(param_2 + 4)) || (*param_3 < (u32)puVar1[3])) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)puVar1;
  }
}
