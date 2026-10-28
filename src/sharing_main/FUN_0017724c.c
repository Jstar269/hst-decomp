/* HSTMATCH module=hstp_trans_main.prx start=0x0017724c end=0x00177284 symbol=FUN_0017724c lang=c99 */
/* Clone of src/eboot/FUN_0016b088.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d2320;

int FUN_0017724c(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_002d2320);
  do {
    if (param_1 == *piVar2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  return 0;
}
