/* HSTMATCH module=hstp_trans_main.prx start=0x0015e86c end=0x0015e8f0 symbol=FUN_0015e86c lang=c99 data=0x00383b5c */
/* Clone of src/eboot/dispatch_id_range_001526e4.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383b5c-0x00383b73) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is unsigned char (lbu) and the if/else tests iVar1 >= 10000 first; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001dbb1c();
extern void FUN_001dbb6c();

u32 FUN_0015e86c(int param_1,u32 param_2)
{
  int iVar1;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("ChangeCamera [%d, %d]\n",*(u32 *)(param_1 + 8),
                 *(u32 *)(param_1 + 0xc));
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 >= 10000) {
    FUN_001dbb1c(DAT_003f344c,iVar1 + -10000,*(u32 *)(param_1 + 0xc));
  }
  else {
    FUN_001dbb6c(DAT_003f344c,iVar1,*(u32 *)(param_1 + 0xc));
  }
  return 0;
}
