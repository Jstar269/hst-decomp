/* HSTMATCH module=EBOOT.BIN start=0x0006ba28 end=0x0006bacc symbol=FUN_0006ba28 lang=c99 */
/* Clone of src/sharing_main/FUN_0006ceb0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d12ba;
extern u8 DAT_002d12bb;
extern u32 * FUN_0006bf30();
extern u32 * FUN_0006cc5c();

void FUN_0006ba28(int *param_1,u32 param_2,int *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_0006bf30(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(int *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0006cc5c(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_002d12ba;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_002d12bb;
  }
}
