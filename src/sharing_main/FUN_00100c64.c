/* HSTMATCH module=hstp_trans_main.prx start=0x00100c64 end=0x00100c80 symbol=FUN_00100c64 lang=c99 */
/* Clone of src/eboot/FUN_000fb528.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_00100c64(int param_1)
{
  u8 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 100);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(u8 *)(iVar2 + 0xb0);
  }
  return uVar1;
}
