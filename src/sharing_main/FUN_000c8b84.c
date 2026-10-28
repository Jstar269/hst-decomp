/* HSTMATCH module=hstp_trans_main.prx start=0x000c8b84 end=0x000c8b94 symbol=FUN_000c8b84 lang=c99 */
/* Clone of src/eboot/FUN_000c5100.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000c8b84(int param_1)
{
  *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
}
