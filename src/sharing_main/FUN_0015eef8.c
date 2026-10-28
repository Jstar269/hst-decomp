/* HSTMATCH module=hstp_trans_main.prx start=0x0015eef8 end=0x0015ef68 symbol=FUN_0015eef8 lang=c99 data=0x00383be8 */
/* Clone of src/eboot/FUN_00152d70.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383be8-0x00383bfc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
typedef int code();

extern u8 DAT_003e9630;
extern int FUN_00157e10();
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern code * FUN_0023ce60();

u32 FUN_0015eef8(int param_1,u32 *param_2)
{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("GetDifficulty [%d]\n",*(u32 *)(param_1 + 8));
  }
  uVar3 = *param_2;
  iVar1 = (int)(FUN_0023ce60());
  uVar4 = *(u32 *)(iVar1 + 0x138);
  puVar2 = (u32 *)FUN_00157e10(uVar3,*(u32 *)(param_1 + 8));
  *puVar2 = uVar4;
  return 0;
}
