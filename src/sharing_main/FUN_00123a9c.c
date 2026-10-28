/* HSTMATCH module=hstp_trans_main.prx start=0x00123a9c end=0x00123adc symbol=FUN_00123a9c lang=c99 */
/* Clone of src/eboot/FUN_001188c8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0005c688();

void FUN_00123a9c(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_0005c688(iVar1,1);
    *(u32 *)(param_1 + 0xec) = 0;
  }
}
