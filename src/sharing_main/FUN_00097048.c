/* HSTMATCH module=hstp_trans_main.prx start=0x00097048 end=0x00097064 symbol=FUN_00097048 lang=c99 */
/* Clone of src/eboot/FUN_0009503c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00097048(int param_1)
{
  *(u32 *)(param_1 + 0x1b0) = 6;
  *(u32 *)(param_1 + 0x1b4) = 0xffffffff;
  *(u16 *)(param_1 + 0x1b8) = 0;
  *(u8 *)(param_1 + 0x1ba) = 0;
}
