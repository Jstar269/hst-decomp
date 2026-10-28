/* HSTMATCH module=hstp_trans_main.prx start=0x0006d010 end=0x0006d0b4 symbol=FUN_0006d010 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003772ce;
extern u8 DAT_003772cf;
extern u32 * FUN_0006d518();
extern u32 * FUN_0006e244();

void FUN_0006d010(int *param_1,u32 param_2,int *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_0006d518(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(int *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0006e244(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_003772ce;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_003772cf;
  }
}
