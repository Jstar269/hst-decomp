/* HSTMATCH module=hstp_trans_main.prx start=0x000c1090 end=0x000c1098 symbol=FUN_000c1090 lang=c99 */
/* Clone of src/eboot/FUN_000bdb14.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00131ad4();

void FUN_000c1090(int param_1)
{
  FUN_00131ad4(*(u32 *)(param_1 + 0x26c));
}
