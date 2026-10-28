/* HSTMATCH module=hstp_trans_main.prx start=0x001776b4 end=0x001776d4 symbol=FUN_001776b4 lang=c99 */
/* Clone of src/eboot/FUN_0016b4f0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

u16 FUN_001776b4(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(u16 *)(iVar1 + 0x103a);
}
