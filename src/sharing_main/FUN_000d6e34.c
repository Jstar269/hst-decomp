/* HSTMATCH module=hstp_trans_main.prx start=0x000d6e34 end=0x000d6e60 symbol=FUN_000d6e34 lang=c99 */
/* Clone of src/eboot/FUN_000d31d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ec194();

void FUN_000d6e34(int param_1)
{
  if (*(u8 *)(*(int *)(param_1 + 0x180) + 0xd0) != '\0') {
    FUN_000ec194(*(int *)(param_1 + 0x180),0);
  }
}
