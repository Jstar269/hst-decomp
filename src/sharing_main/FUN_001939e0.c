/* HSTMATCH module=hstp_trans_main.prx start=0x001939e0 end=0x001939ec symbol=FUN_001939e0 lang=c99 */
/* Clone of src/eboot/FUN_00187294.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001939e0(int param_1,u8 param_2)
{
  *(u8 *)(*(int *)(param_1 + 0x1180) + 0x12d) = param_2;
}
