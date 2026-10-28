/* HSTMATCH module=hstp_trans_main.prx start=0x00125188 end=0x001251d8 symbol=FUN_00125188 lang=c99 */
/* Clone of src/eboot/FUN_00119fb4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;

void FUN_00125188(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(DAT_003e19f0 + 0xa0);
  *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + *(int *)(param_1 + 0xf4);
  *(int *)(iVar1 + 0x110) = *(int *)(iVar1 + 0x110) + *(int *)(param_1 + 0xf8);
  *(int *)(iVar1 + 0x16c) = *(int *)(iVar1 + 0x16c) + *(int *)(param_1 + 0xfc);
  *(int *)(iVar1 + 0x1c8) = *(int *)(iVar1 + 0x1c8) + *(int *)(param_1 + 0x100);
}
