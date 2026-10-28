/* HSTMATCH module=hstp_trans_main.prx start=0x000fae6c end=0x000fae98 symbol=FUN_000fae6c lang=c99 */
/* Clone of src/eboot/FUN_000eecc4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_000fae6c(int param_1)
{
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
