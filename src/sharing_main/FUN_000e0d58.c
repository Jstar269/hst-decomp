/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d58 end=0x000e0d70 symbol=FUN_000e0d58 lang=c99 */
/* Clone of src/eboot/FUN_000dcc54.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000e0d58(int param_1,u32 param_2)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u32 *)(param_1 + 0x7c) = param_2;
  }
}
