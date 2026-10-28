/* HSTMATCH module=hstp_trans_main.prx start=0x001773a0 end=0x001773c0 symbol=FUN_001773a0 lang=c99 */
/* Clone of src/eboot/FUN_0016b1dc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001773e0();

u8 FUN_001773a0(void)
{
  int iVar1;
  
  iVar1 = FUN_001773e0();
  return *(u8 *)(iVar1 + 1);
}
