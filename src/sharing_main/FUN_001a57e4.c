/* HSTMATCH module=hstp_trans_main.prx start=0x001a57e4 end=0x001a57ec symbol=FUN_001a57e4 lang=c99 */
/* Clone of src/eboot/FUN_00198de0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001a57e4(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0xc0) = param_2;
}
