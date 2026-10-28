/* HSTMATCH module=hstp_trans_main.prx start=0x001f52f8 end=0x001f5300 symbol=FUN_001f52f8 lang=c99 */
/* Clone of src/eboot/FUN_001e70e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022d170();

void FUN_001f52f8(int param_1)
{
  FUN_0022d170(*(u32 *)(param_1 + 0x1d64));
}
