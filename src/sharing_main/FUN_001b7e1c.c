/* HSTMATCH module=hstp_trans_main.prx start=0x001b7e1c end=0x001b7f74 symbol=FUN_001b7e1c lang=c99 */
/* Clone of src/eboot/FUN_001aa850.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003899a0;
extern void FUN_00105470();
extern void FUN_00113a50();
extern u8 * FUN_0020d1e0();

void FUN_001b7e1c(u32 *param_1,int *param_2,u32 *param_3,u32 *param_4, int param_5,int param_6,int param_7,int param_8,int iStackX_0)
{
  u32 uVar1;
  int iVar2;
  
  FUN_00105470(*param_1,1);
  FUN_00105470(*param_3,0);
  FUN_00105470(*param_2,0);
  *(int *)(*param_2 + 0x24) = *(int *)(*param_2 + 0x28) + 0x11;
  uVar1 = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  iVar2 = *(int *)(param_5 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_00113a50();
  uVar1 = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  iVar2 = *(int *)(param_6 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_00113a50();
  iVar2 = *(int *)(param_7 + 4);
  *(u8 **)(iVar2 + 0xf8) = &DAT_003899a0;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_00113a50();
  uVar1 = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  iVar2 = *(int *)(param_8 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_00113a50();
  FUN_00105470(*param_4,1);
  uVar1 = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  iVar2 = *(int *)(iStackX_0 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_00113a50();
}
