/* HSTMATCH module=hstp_trans_main.prx start=0x000cbd60 end=0x000cbd8c symbol=FUN_000cbd60 lang=c99 */
/* Clone of src/eboot/FUN_000c81c0.c (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000d2328();

u32 FUN_000cbd60(int param_1)
{
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_000d2328(*(int *)(param_1 + 0x44));
  }
  return 1;
}
