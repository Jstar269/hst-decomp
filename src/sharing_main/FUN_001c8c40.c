/* HSTMATCH module=hstp_trans_main.prx start=0x001c8c40 end=0x001c8c6c symbol=FUN_001c8c40 lang=c99 */
/* Clone of src/eboot/FUN_001baef8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001c8c40(int param_1,int param_2)
{
  u8 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x60);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(u8 *)(iVar2 + 0x171);
  }
  return uVar1;
}
