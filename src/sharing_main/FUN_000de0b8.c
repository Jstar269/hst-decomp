/* HSTMATCH module=hstp_trans_main.prx start=0x000de0b8 end=0x000de15c symbol=FUN_000de0b8 lang=c99 */
/* Clone of src/eboot/FUN_000da0f8.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037d702;
extern u8 DAT_0037d703;
extern u32 * FUN_000de300();
extern u32 * FUN_000deaf0();

void FUN_000de0b8(int *param_1,u32 param_2,short *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_000de300(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(short *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_000deaf0(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_0037d702;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_0037d703;
  }
}
