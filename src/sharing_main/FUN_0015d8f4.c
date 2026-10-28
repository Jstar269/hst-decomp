/* HSTMATCH module=hstp_trans_main.prx start=0x0015d8f4 end=0x0015d974 symbol=FUN_0015d8f4 lang=c99 data=0x00383a28 */
/* Clone of src/eboot/FUN_0015184c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383a28-0x00383a3c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d5588();

u32 FUN_0015d8f4(int param_1,int param_2)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(*(int *)(param_2 + 0xc) + 0x30);
  FUN_001d5588(DAT_003f344c,uVar1,*(u32 *)(param_1 + 8));
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("SetMyLavel [%d:%s]\n",uVar1,*(u32 *)(param_1 + 8));
  }
  return 0;
}
