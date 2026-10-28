/* HSTMATCH module=hstp_trans_main.prx start=0x001b1780 end=0x001b179c symbol=FUN_001b1780 lang=c99 */
/* Clone of src/eboot/FUN_001a41b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001b1780(int param_1)
{
  *(u32 *)(param_1 + 0x2cc) = *(u32 *)(param_1 + 0x2c0);
  *(u32 *)(param_1 + 0x2d0) = *(u32 *)(param_1 + 0x2c4);
  *(u32 *)(param_1 + 0x2d4) = *(u32 *)(param_1 + 0x2c8);
}
