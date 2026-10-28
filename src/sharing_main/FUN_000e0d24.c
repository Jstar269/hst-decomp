/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d24 end=0x000e0d40 symbol=FUN_000e0d24 lang=c99 */
/* Clone of src/eboot/FUN_000dcc20.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000e0d24(int param_1,u32 param_2,u32 param_3)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u32 *)(param_1 + 0x68) = param_2;
    *(u32 *)(param_1 + 0x6c) = param_3;
  }
}
