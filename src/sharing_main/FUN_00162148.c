/* HSTMATCH module=hstp_trans_main.prx start=0x00162148 end=0x001621b4 symbol=FUN_00162148 lang=c99 data=0x00384078 */
/* Clone of src/eboot/FUN_00155c40.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00384078-0x0038408b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern int FUN_001d54e8();
extern void FUN_002a4d70();

u32 FUN_00162148(int param_1,u32 param_2)
{
  int iVar1;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("UnlinkKomono [%d]\n",*(u32 *)(param_1 + 8));
  }
  iVar1 = FUN_001d54e8(DAT_003f344c,*(u32 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_002a4d70(iVar1,0);
  }
  return 0;
}
