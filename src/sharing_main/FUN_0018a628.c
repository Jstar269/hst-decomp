/* HSTMATCH module=hstp_trans_main.prx start=0x0018a628 end=0x0018a638 symbol=FUN_0018a628 lang=c99 */
/* Clone of src/eboot/FUN_0017df34.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0018a628(int param_1)
{
  *(u8 *)(param_1 + 0x41) = 1;
  *(u32 *)(param_1 + 0x44) = 0;
}
