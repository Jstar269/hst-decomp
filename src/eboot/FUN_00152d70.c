/* HSTMATCH module=EBOOT.BIN start=0x00152d70 end=0x00152de0 symbol=FUN_00152d70 lang=c99 data=0x002dc700 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc700-0x002dc714) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
typedef int code();

extern u8 DAT_003402f0;
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern code * FUN_0022cd60();

u32 FUN_00152d70(int param_1,u32 *param_2)
{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("GetDifficulty [%d]\n",*(u32 *)(param_1 + 8));
  }
  uVar3 = *param_2;
  iVar1 = (int)(FUN_0022cd60());
  uVar4 = *(u32 *)(iVar1 + 0x138);
  puVar2 = (u32 *)FUN_0014c384(uVar3,*(u32 *)(param_1 + 8));
  *puVar2 = uVar4;
  return 0;
}
