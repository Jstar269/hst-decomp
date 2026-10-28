/* HSTMATCH module=hstp_trans_main.prx start=0x00177c3c end=0x00177c64 symbol=FUN_00177c3c lang=c99 */
/* Clone of src/eboot/FUN_0016ba78.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

void FUN_00177c3c(u8 param_1)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  *(u8 *)(iVar1 + 0x103c) = param_1;
}
