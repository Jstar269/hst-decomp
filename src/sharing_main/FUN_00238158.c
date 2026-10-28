/* HSTMATCH module=hstp_trans_main.prx start=0x00238158 end=0x002381f0 symbol=FUN_00238158 lang=c99 */
/* Clone of src/eboot/FUN_00228be4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005ffd8();

void FUN_00238158(int param_1)
{
  int iVar1;
  
  if ((*(u8 *)(param_1 + 0x435) != '\0') && (*(u8 *)(param_1 + 0x436) != '\0')) {
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 == 1) {
      FUN_0005ffd8(param_1 + 0xb0,0);
    }
    else if ((iVar1 == 2) || (iVar1 == 4)) {
      FUN_0005ffd8(param_1 + 0xb0,0);
    }
    else if ((iVar1 == 3) || (iVar1 == 5)) {
      FUN_0005ffd8(param_1 + 0x260,0);
    }
  }
}
