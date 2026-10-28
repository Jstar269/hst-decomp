/* HSTMATCH module=hstp_trans_main.prx start=0x00207b64 end=0x00207b70 symbol=FUN_00207b64 lang=c99 */
/* Clone of src/eboot/FUN_001f94ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001f5e7c();

void FUN_00207b64(int param_1)
{
  FUN_001f5e7c(*(u32 *)(param_1 + 0x510),1);
}
