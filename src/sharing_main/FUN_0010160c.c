/* HSTMATCH module=hstp_trans_main.prx start=0x0010160c end=0x00101620 symbol=FUN_0010160c lang=c99 */
/* Clone of src/eboot/FUN_000fbed0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0010160c(int param_1,int param_2)
{
  *(char *)(param_1 + 0x58) = (char)param_2;
  if (param_2 != 0) {
    *(u32 *)(param_1 + 0x5c) = 0;
  }
}
