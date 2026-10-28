/* HSTMATCH module=hstp_trans_main.prx start=0x001e0fc4 end=0x001e0fcc symbol=FUN_001e0fc4 lang=c99 */
/* Clone of src/eboot/FUN_001d31c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001e0fc4(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x84) = param_2;
}
