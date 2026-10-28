/* HSTMATCH module=hstp_trans_main.prx start=0x00161228 end=0x00161290 symbol=FUN_00161228 lang=c99 data=0x00383ef0 */
/* Clone of src/eboot/FUN_00154dc8.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383ef0-0x00383f0a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001dbc38();

u32 FUN_00161228(int param_1,u32 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("MoveCamera [%d, %d (%d)]\n",*(u32 *)(param_1 + 8),
                 *(u32 *)(param_1 + 0xc),*(u32 *)(param_1 + 0x10));
  }
  FUN_001dbc38(DAT_003f344c,*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0x10),
               *(u32 *)(param_1 + 0xc));
  return 0;
}
