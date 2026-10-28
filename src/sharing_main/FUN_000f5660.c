/* HSTMATCH module=hstp_trans_main.prx start=0x000f5660 end=0x000f5668 symbol=FUN_000f5660 lang=c99 */
/* Clone of src/eboot/FUN_000eff98.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000f5660(int param_1,u16 param_2)
{
  *(u16 *)(param_1 + 0x104) = param_2;
}
