/* HSTMATCH module=EBOOT.BIN start=0x0006b5f8 end=0x0006b69c symbol=FUN_0006b5f8 lang=c99 */
/* Clone of src/eboot/FUN_00229af0.c (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d12be;
extern u8 DAT_002d12bf;
extern u32 * FUN_0006c044();
extern u32 * FUN_0006c3b0();

void FUN_0006b5f8(int *param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_0006c044(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(u32 *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0006c3b0(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_002d12be;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_002d12bf;
  }
}
