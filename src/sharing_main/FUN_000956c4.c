/* HSTMATCH module=hstp_trans_main.prx start=0x000956c4 end=0x000956ec symbol=FUN_000956c4 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059ba8();

void FUN_000956c4(int param_1,u32 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00059ba8(*(int *)(param_1 + 0x58),param_2);
  }
}
