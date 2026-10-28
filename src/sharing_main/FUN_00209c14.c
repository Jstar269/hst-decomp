/* HSTMATCH module=hstp_trans_main.prx start=0x00209c14 end=0x00209c3c symbol=FUN_00209c14 lang=c99 */
/* Clone of src/eboot/FUN_001fb4fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eabf4;

bool FUN_00209c14(int param_1)
{
  return (&DAT_003eabf4)[*(int *)(param_1 + 0x3cc) * 0x120] != '\0';
}
