/* HSTMATCH module=hstp_trans_main.prx start=0x00100be8 end=0x00100c0c symbol=FUN_00100be8 lang=c99 */
/* Clone of src/eboot/FUN_000fb4ac.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00100be8(int param_1,u8 param_2)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x8c), iVar1 != 0)) {
    *(u8 *)(iVar1 + 0x870) = param_2;
  }
}
