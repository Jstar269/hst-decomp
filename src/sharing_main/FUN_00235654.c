/* HSTMATCH module=hstp_trans_main.prx start=0x00235654 end=0x0023568c symbol=FUN_00235654 lang=c99 */
/* Clone of src/eboot/FUN_002260e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_00235654(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x24);
  FUN_00108f54(iVar1,1);
  *(u8 *)(iVar1 + 0x54) = 1;
}
