/* HSTMATCH module=hstp_trans_main.prx start=0x001b1844 end=0x001b1860 symbol=FUN_001b1844 lang=c99 */
/* Clone of src/eboot/FUN_001a4278.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001b1844(int param_1)
{
  *(u32 *)(param_1 + 0x2e8) = *(u32 *)(param_1 + 0x2e4);
  *(u32 *)(param_1 + 0x2f0) = *(u32 *)(param_1 + 0x2ec);
  *(u32 *)(param_1 + 0x2f8) = *(u32 *)(param_1 + 0x2f4);
}
