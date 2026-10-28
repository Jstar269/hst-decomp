/* HSTMATCH module=hstp_trans_main.prx start=0x000c0ea0 end=0x000c0ea8 symbol=FUN_000c0ea0 lang=c99 */
/* Clone of src/eboot/FUN_000bd924.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000c0ea0(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x284) = param_2;
}
