/* HSTMATCH module=hstp_trans_main.prx start=0x001006f4 end=0x00100728 symbol=FUN_001006f4 lang=c99 */
/* Clone of src/eboot/FUN_000fafb8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern void FUN_000fe984();

void FUN_001006f4(int param_1)
{
  if (*(int *)(DAT_003e19f0 + 0x3c) != 9) {
    FUN_000fe984(*(u32 *)(param_1 + 0x3c));
  }
}
