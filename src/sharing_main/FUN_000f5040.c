/* HSTMATCH module=hstp_trans_main.prx start=0x000f5040 end=0x000f5070 symbol=FUN_000f5040 lang=c99 */
/* Clone of src/eboot/FUN_000ef978.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f4c2c();
extern void FUN_000f50a0();

void FUN_000f5040(u32 param_1)
{
  FUN_000f50a0();
  FUN_000f4c2c(param_1,0);
}
