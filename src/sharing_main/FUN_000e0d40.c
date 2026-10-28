/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d40 end=0x000e0d58 symbol=FUN_000e0d40 lang=c99 */
/* Clone of src/eboot/FUN_000dcc3c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000e0d40(int param_1,u8 param_2)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u8 *)(param_1 + 0x70) = param_2;
  }
}
