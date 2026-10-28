/* HSTMATCH module=hstp_trans_main.prx start=0x0013c0f4 end=0x0013c100 symbol=FUN_0013c0f4 lang=c99 */
/* Clone of src/eboot/FUN_00130b3c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0013c0f4(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x3c) = 0;
  *(u32 *)(param_1 + 0x40) = param_2;
}
