/* HSTMATCH module=hstp_trans_main.prx start=0x0017729c end=0x001772d4 symbol=FUN_0017729c lang=c99 */
/* Clone of src/eboot/FUN_0016b088.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d232c;

int FUN_0017729c(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_002d232c);
  do {
    if (param_1 == *piVar2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  return 0;
}
