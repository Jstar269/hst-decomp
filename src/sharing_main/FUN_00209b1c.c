/* HSTMATCH module=hstp_trans_main.prx start=0x00209b1c end=0x00209b64 symbol=FUN_00209b1c lang=c99 */
/* Clone of src/eboot/FUN_001fb404.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern int FUN_001bfc3c();

void FUN_00209b1c(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x12d0) == -1) {
    iVar1 = FUN_001bfc3c((int *)&DAT_003eaad8,0x10);
    *(int *)(param_1 + 0x12d0) = iVar1;
    *(u32 *)(param_1 + 0x12d4) = 0;
  }
}
