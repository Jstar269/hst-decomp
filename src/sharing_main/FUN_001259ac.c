/* HSTMATCH module=hstp_trans_main.prx start=0x001259ac end=0x001259f4 symbol=FUN_001259ac lang=c99 */
/* Clone of src/eboot/FUN_0011a7d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e84;

u32 FUN_001259ac(int param_1)
{
  int iVar1;
  
  if (*(int *)(DAT_003e1e84 + 0x8c) == 0) {
    iVar1 = 0;
    do {
      if (*(int *)(param_1 + 0x314) == 5) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 4;
    } while (iVar1 < 2);
  }
  return 0;
}
