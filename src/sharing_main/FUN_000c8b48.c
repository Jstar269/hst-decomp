/* HSTMATCH module=hstp_trans_main.prx start=0x000c8b48 end=0x000c8b50 symbol=FUN_000c8b48 lang=c99 */
/* Clone of src/eboot/FUN_000c50c4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00297820();

void FUN_000c8b48(int param_1)
{
  FUN_00297820(*(u32 *)(param_1 + 0x784));
}
