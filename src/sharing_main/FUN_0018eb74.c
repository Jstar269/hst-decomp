/* HSTMATCH module=hstp_trans_main.prx start=0x0018eb74 end=0x0018eca0 symbol=FUN_0018eb74 lang=c99 */
/* Clone of src/eboot/FUN_00182480.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_001118ac();
extern void FUN_00111b58();
extern u32 FUN_00177e98();
extern void FUN_0018e8a4();
extern void FUN_001920bc();
extern void FUN_001929e8();

void FUN_0018eb74(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8, u8 uStackX_0)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_00177e98();
  uVar2 = (**(code **)(iVar1 + 0x558))();
  FUN_0018e8a4(param_1,uVar2);
  FUN_001118ac(*(u32 *)(param_1 + 0x285c),0xd,0x11);
  FUN_00111b58(*(u32 *)(param_1 + 0x285c),param_2,0);
  FUN_001920bc(param_1,param_2,param_3,param_4,param_5,param_7,param_6,1,param_8,uStackX_0);
  iVar1 = FUN_00177e98();
  if (*(int *)(*(int *)(iVar1 + 0x5c0) + *(int *)(iVar1 + 0x5b8) * 4) != 4) {
    FUN_001929e8(param_1,param_2,param_3,param_4,param_5,0,param_7,param_8);
  }
}
