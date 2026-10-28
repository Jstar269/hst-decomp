/* HSTMATCH module=hstp_trans_main.prx start=0x000bc540 end=0x000bc54c symbol=FUN_000bc540 lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003da704;
extern void FUN_000bc170();

void FUN_000bc540(u32 param_1)
{
  FUN_000bc170(param_1,DAT_003da704);
}
