/* HSTMATCH module=hstp_trans_main.prx start=0x001934b0 end=0x001934c8 symbol=FUN_001934b0 lang=c99 */
/* Clone of src/eboot/FUN_00186d64.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00111b58();

void FUN_001934b0(int param_1,int param_2,int param_3,int param_4)
{
  FUN_00111b58(*(u32 *)(param_1 + 0x285c),param_2 + (param_3 - param_4) * 4,0);
}
