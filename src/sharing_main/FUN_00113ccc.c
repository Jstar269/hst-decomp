/* HSTMATCH module=hstp_trans_main.prx start=0x00113ccc end=0x00113cf4 symbol=FUN_00113ccc lang=c99 */
/* Clone of src/eboot/FUN_0010d724.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00107ddc();

void FUN_00113ccc(int param_1)
{
  FUN_00107ddc();
  *(u32 *)(param_1 + 0xf8) = 0;
}
