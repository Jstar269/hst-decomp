/* HSTMATCH module=hstp_trans_main.prx start=0x002b04ac end=0x002b04e4 symbol=FUN_002b04ac lang=c99 */
/* Clone of src/eboot/FUN_002a10a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

void FUN_002b04ac(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0001342c();
  *(int *)(param_1 + 0x1d8) = iVar1 % 0x96 + 0x96;
}
