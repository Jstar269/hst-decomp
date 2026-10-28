/* HSTMATCH module=hstp_trans_main.prx start=0x000e1d9c end=0x000e1e58 symbol=FUN_000e1d9c lang=c99 */
/* Clone of src/eboot/FUN_000ddbb0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern int FUN_00089f84();

void FUN_000e1d9c(u32 param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = FUN_00089f84(DAT_003e19f0);
  if (param_3 == *(int *)(iVar1 + 0x144)) {
    *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 500) =
         *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 500) + 1;
    iVar1 = FUN_00089f84(DAT_003e19f0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f0) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f0) + 1;
    }
  }
  else {
    iVar1 = FUN_00089f84(DAT_003e19f0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f8) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f8) + 1;
    }
  }
}
