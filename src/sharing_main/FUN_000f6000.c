/* HSTMATCH module=hstp_trans_main.prx start=0x000f6000 end=0x000f6030 symbol=FUN_000f6000 lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_000f6000(int param_1)
{
  FUN_00108f54(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
}
