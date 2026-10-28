/* HSTMATCH module=hstp_trans_main.prx start=0x0015d730 end=0x0015d7c4 symbol=FUN_0015d730 lang=c99 data=0x003839f0 */
/* Clone of src/eboot/scene_call_chain_00151688.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003839f0-0x00383a0a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: DAT_003e9630 is unsigned char (lbu), local declaration order uVar4, uVar3, uVar2 for the saved-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern int FUN_00157e10();
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern bool FUN_0023b388();

u32 FUN_0015d730(u32 param_1,u32 *param_2)
{
  u32 uVar4;
  u32 uVar3;
  u32 uVar2;
  u32 *puVar1;
  
  uVar3 = *(u32 *)(param_2[3] + 0x34);
  uVar2 = *(u32 *)(param_2[3] + 0x38);
  puVar1 = (u32 *)FUN_00157e10(*param_2,8);
  uVar4 = *puVar1;
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("CmdCheckTalkProc(%d, %d)\n",uVar3,uVar4);
  }
  FUN_0023b388(uVar3,uVar2,uVar4);
  return 0;
}
