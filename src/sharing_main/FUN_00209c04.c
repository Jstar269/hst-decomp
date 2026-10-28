/* HSTMATCH module=hstp_trans_main.prx start=0x00209c04 end=0x00209c14 symbol=FUN_00209c04 lang=c99 */
/* Clone of src/eboot/FUN_001fb4ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_00209c04(int param_1)
{
  return *(int *)(param_1 + 0x12d0) == -1;
}
