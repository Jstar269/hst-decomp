/* HSTMATCH module=hstp_trans_main.prx start=0x001bd0e4 end=0x001bd0f0 symbol=FUN_001bd0e4 lang=c99 */
/* Clone of src/eboot/FUN_001af8d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001baf04();

void FUN_001bd0e4(int param_1)
{
  FUN_001baf04(*(u32 *)(param_1 + 0xc),1);
}
