/* HSTMATCH module=EBOOT.BIN start=0x001825ac end=0x001826b8 symbol=FUN_001825ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern u32 FUN_0016bc70();
extern void FUN_001821b0();
extern void FUN_00185970();
extern void FUN_0018629c();

void FUN_001825ac(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8, u8 uStackX_0)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_0016bc70();
  uVar2 = (**(code **)(iVar1 + 0x558))();
  FUN_001821b0(param_1,uVar2);
  FUN_00185970(param_1,param_2,param_3,param_4,param_5,param_7,param_6,0,param_8,uStackX_0);
  iVar1 = FUN_0016bc70();
  if (*(int *)(*(int *)(iVar1 + 0x5c0) + *(int *)(iVar1 + 0x5b8) * 4) != 4) {
    FUN_0018629c(param_1,param_2,param_3,param_4,param_5,1,param_7,param_8);
  }
}
