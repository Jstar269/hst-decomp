/* HSTMATCH module=EBOOT.BIN start=0x001aa850 end=0x001aa9a8 symbol=FUN_001aa850 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e20d0;
extern void FUN_000ffb3c();
extern void FUN_0010d4a8();
extern u8 * FUN_001fea10();

void FUN_001aa850(u32 *param_1,int *param_2,u32 *param_3,u32 *param_4, int param_5,int param_6,int param_7,int param_8,int iStackX_0)
{
  u32 uVar1;
  int iVar2;
  
  FUN_000ffb3c(*param_1,1);
  FUN_000ffb3c(*param_3,0);
  FUN_000ffb3c(*param_2,0);
  *(int *)(*param_2 + 0x24) = *(int *)(*param_2 + 0x28) + 0x11;
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_5 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_6 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  iVar2 = *(int *)(param_7 + 4);
  *(u8 **)(iVar2 + 0xf8) = &DAT_002e20d0;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_8 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  FUN_000ffb3c(*param_4,1);
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(iStackX_0 + 4);
  *(u32 *)(iVar2 + 0xf8) = uVar1;
  *(u32 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
}
