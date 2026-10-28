/* HSTMATCH module=hstp_trans_main.prx start=0x001776d4 end=0x001776f8 symbol=FUN_001776d4 lang=c99 */
/* Clone of src/eboot/FUN_0016b510.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

bool FUN_001776d4(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(u8 *)(iVar1 + 0x103c) != '\0';
}
