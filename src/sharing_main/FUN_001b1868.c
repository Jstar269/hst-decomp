/* HSTMATCH module=hstp_trans_main.prx start=0x001b1868 end=0x001b1884 symbol=FUN_001b1868 lang=c99 */
/* Clone of src/eboot/FUN_001a429c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001b1868(int param_1)
{
  *(u32 *)(param_1 + 0x308) = *(u32 *)(param_1 + 0x2fc);
  *(u32 *)(param_1 + 0x30c) = *(u32 *)(param_1 + 0x300);
  *(u32 *)(param_1 + 0x310) = *(u32 *)(param_1 + 0x304);
}
