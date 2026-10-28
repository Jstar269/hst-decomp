/* HSTMATCH module=hstp_trans_main.prx start=0x00239064 end=0x00239108 symbol=FUN_00239064 lang=c99 */
/* Clone of src/eboot/FUN_00229af0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0039af23;
extern u8 DAT_0039af24;
extern u32 * FUN_00239164();
extern u32 * FUN_002398dc();

void FUN_00239064(int *param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_00239164(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(u32 *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_002398dc(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_0039af23;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_0039af24;
  }
}
