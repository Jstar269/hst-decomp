/* HSTMATCH module=hstp_trans_main.prx start=0x002b1770 end=0x002b17cc symbol=FUN_002b1770 lang=c99 */
/* Clone of src/eboot/FUN_002a23d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern int FUN_001bfc3c();
extern void FUN_002b136c();

void FUN_002b1770(int param_1)
{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x1b0) == 5) && (piVar1 = *(int **)(param_1 + 0x1d0), *piVar1 == 1)) {
    FUN_001bfc3c((int *)&DAT_003eaad8,0xf);
    FUN_002b136c(piVar1,2);
  }
}
