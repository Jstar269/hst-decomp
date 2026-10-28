/* HSTMATCH module=hstp_trans_main.prx start=0x001f5f08 end=0x001f5f40 symbol=FUN_001f5f08 lang=c99 */
/* Clone of src/eboot/FUN_001e7cf0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00226954();

void FUN_001f5f08(int param_1)
{
  FUN_00226954(param_1 + 0x252c,0x80,0,10);
  *(u32 *)(param_1 + 0x2528) = 0;
}
