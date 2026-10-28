/* HSTMATCH module=hstp_trans_main.prx start=0x00200d40 end=0x00200d48 symbol=FUN_00200d40 lang=c99 */
/* Clone of src/eboot/FUN_001f293c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00225c2c();

void FUN_00200d40(int param_1)
{
  FUN_00225c2c(*(u32 *)(param_1 + 0x560));
}
