/* HSTMATCH module=hstp_trans_main.prx start=0x000f435c end=0x000f438c symbol=FUN_000f435c lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_000f435c(int param_1)
{
  FUN_00108f54(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
}
