/* HSTMATCH module=hstp_trans_main.prx start=0x00095714 end=0x0009573c symbol=FUN_00095714 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059c1c();

void FUN_00095714(int param_1,u32 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00059c1c(*(int *)(param_1 + 0x58),param_2);
  }
}
