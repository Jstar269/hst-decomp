/* HSTMATCH module=hstp_trans_main.prx start=0x00123558 end=0x00123588 symbol=FUN_00123558 lang=c99 */
/* Clone of src/eboot/FUN_00118384.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00123588();

int FUN_00123558(int param_1)
{
  FUN_00123588();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
