/* HSTMATCH module=hstp_trans_main.prx start=0x0006cbe0 end=0x0006cc84 symbol=FUN_0006cbe0 lang=c99 */
/* Clone of src/eboot/FUN_00229af0.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003772d2;
extern u8 DAT_003772d3;
extern u32 * FUN_0006d62c();
extern u32 * FUN_0006d998();

void FUN_0006cbe0(int *param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_0006d62c(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(u32 *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0006d998(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_003772d2;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_003772d3;
  }
}
