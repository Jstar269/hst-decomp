/* HSTMATCH module=hstp_trans_main.prx start=0x002b0468 end=0x002b04ac symbol=FUN_002b0468 lang=c99 */
/* Clone of src/eboot/FUN_002a105c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

void FUN_002b0468(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0001342c();
  *(int *)(param_1 + 0x1f0) = (iVar1 % 0xc) * 0x1e + 0x78;
}
