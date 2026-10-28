/* HSTMATCH module=hstp_trans_main.prx start=0x0015cd14 end=0x0015cd5c symbol=FUN_0015cd14 lang=c99 data=0x00383944 */
/* Clone of src/eboot/debug_flag_notify_00150cdc.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383944-0x00383951) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is an unsigned char flag (lbu), not u32; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001dbaac();

u32 FUN_0015cd14(u32 param_1,u32 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("EnalbeInput\n");
  }
  FUN_001dbaac(DAT_003f344c);
  return 0;
}
