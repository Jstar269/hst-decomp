/* HSTMATCH module=EBOOT.BIN start=0x00182480 end=0x001825ac symbol=FUN_00182480 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_0010b6d4();
extern void FUN_0010b980();
extern u32 FUN_0016bc70();
extern void FUN_001821b0();
extern void FUN_00185970();
extern void FUN_0018629c();

void FUN_00182480(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8, u8 uStackX_0)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_0016bc70();
  uVar2 = (**(code **)(iVar1 + 0x558))();
  FUN_001821b0(param_1,uVar2);
  FUN_0010b6d4(*(u32 *)(param_1 + 0x285c),0xd,0x11);
  FUN_0010b980(*(u32 *)(param_1 + 0x285c),param_2,0);
  FUN_00185970(param_1,param_2,param_3,param_4,param_5,param_7,param_6,1,param_8,uStackX_0);
  iVar1 = FUN_0016bc70();
  if (*(int *)(*(int *)(iVar1 + 0x5c0) + *(int *)(iVar1 + 0x5b8) * 4) != 4) {
    FUN_0018629c(param_1,param_2,param_3,param_4,param_5,0,param_7,param_8);
  }
}
