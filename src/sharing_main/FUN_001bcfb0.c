/* HSTMATCH module=hstp_trans_main.prx start=0x001bcfb0 end=0x001bcfbc symbol=FUN_001bcfb0 lang=c99 */
/* Clone of src/eboot/FUN_001af8d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ba298();

void FUN_001bcfb0(int param_1)
{
  FUN_001ba298(*(u32 *)(param_1 + 0xc),1);
}
