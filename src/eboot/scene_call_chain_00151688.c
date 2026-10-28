/* HSTMATCH module=EBOOT.BIN start=0x00151688 end=0x0015171c symbol=FUN_00151688 lang=c99 data=0x002dc508 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), local declaration order uVar4, uVar3, uVar2 for the saved-register assignment; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc508-0x002dc522) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern bool FUN_0022baec();

u32 FUN_00151688(u32 param_1,u32 *param_2)
{
  u32 uVar4;
  u32 uVar3;
  u32 uVar2;
  u32 *puVar1;
  
  uVar3 = *(u32 *)(param_2[3] + 0x34);
  uVar2 = *(u32 *)(param_2[3] + 0x38);
  puVar1 = (u32 *)FUN_0014c384(*param_2,8);
  uVar4 = *puVar1;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("CmdCheckTalkProc(%d, %d)\n",uVar3,uVar4);
  }
  FUN_0022baec(uVar3,uVar2,uVar4);
  return 0;
}
