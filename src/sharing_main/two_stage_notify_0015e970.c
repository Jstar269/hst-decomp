/* HSTMATCH module=hstp_trans_main.prx start=0x0015e970 end=0x0015e9e0 symbol=FUN_0015e970 lang=c99 data=0x00383b74 */
/* Clone of src/eboot/two_stage_notify_001527e8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383b74-0x00383b84) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is an unsigned char flag (lbu), not u32; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_00299000();

u32 FUN_0015e970(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_00299000(*(int *)(param_2 + 0xc),*(u32 *)(param_1 + 0xc),*(u32 *)(param_1 + 8)
                );
  }
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("SePlay [%s:%d]\n",*(u32 *)(param_1 + 0xc),
                 *(u32 *)(param_1 + 8));
  }
  return 0;
}
