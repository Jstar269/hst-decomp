/* HSTMATCH module=hstp_trans_main.prx start=0x00120bb8 end=0x00120bc0 symbol=FUN_00120bb8 lang=c99 */
/* Clone of src/eboot/FUN_00115c9c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00120bb8(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x144) = param_2;
}
