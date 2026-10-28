/* HSTMATCH module=hstp_trans_main.prx start=0x00098ee4 end=0x00098f50 symbol=FUN_00098ee4 lang=c99 */
/* Clone of src/eboot/FUN_00096dac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern void FUN_00099248();

void FUN_00098ee4(void)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  if (DAT_003e19f0 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = *(int *)(DAT_003e19f0 + iVar2 + 0x70);
      if (iVar1 != 0) {
        FUN_00099248(iVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < 4);
  }
}
