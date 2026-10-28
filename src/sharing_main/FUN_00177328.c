/* HSTMATCH module=hstp_trans_main.prx start=0x00177328 end=0x00177348 symbol=FUN_00177328 lang=c99 */
/* Clone of src/eboot/FUN_0016b164.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

u16 FUN_00177328(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(u16 *)(iVar1 + 0x103e);
}
