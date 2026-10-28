/* HSTMATCH module=hstp_trans_main.prx start=0x000f59e4 end=0x000f5a18 symbol=FUN_000f59e4 lang=c99 */
/* Clone of src/eboot/FUN_000f031c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_000f59e4(int param_1)
{
  FUN_00108f54(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
  *(u32 *)(param_1 + 0x94) = 0;
}
