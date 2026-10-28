/* HSTMATCH module=hstp_trans_main.prx start=0x000d2828 end=0x000d2854 symbol=FUN_000d2828 lang=c99 */
/* Clone of src/eboot/FUN_000cec2c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005ffd8();

void FUN_000d2828(int param_1)
{
  if (*(u8 *)(param_1 + 0x3c) != '\0') {
    FUN_0005ffd8(param_1 + 0x40,0);
  }
}
