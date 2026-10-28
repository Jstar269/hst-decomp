/* HSTMATCH module=hstp_trans_main.prx start=0x001604f8 end=0x00160550 symbol=FUN_001604f8 lang=c99 data=0x00383d58 */
/* Clone of src/eboot/notify_dispatch_001541b0.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383d58-0x00383d71) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is an unsigned char flag (lbu); exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d6284();

u32 FUN_001604f8(int param_1,u32 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("Target Camera[point:%d]\n",*(u32 *)(param_1 + 8));
  }
  FUN_001d6284(DAT_003f344c,*(u32 *)(param_1 + 8));
  return 0;
}
