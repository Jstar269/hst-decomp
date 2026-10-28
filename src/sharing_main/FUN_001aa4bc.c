/* HSTMATCH module=hstp_trans_main.prx start=0x001aa4bc end=0x001aa4c8 symbol=FUN_001aa4bc lang=c99 */
/* Clone of src/eboot/FUN_0019cf80.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001aa4bc(int param_1)
{
  *(u32 *)(param_1 + 0xc) = 0;
  *(u8 *)(param_1 + 0x52) = 0;
}
