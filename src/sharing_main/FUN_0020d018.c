/* HSTMATCH module=hstp_trans_main.prx start=0x0020d018 end=0x0020d058 symbol=FUN_0020d018 lang=c99 */
/* Clone of src/eboot/FUN_001fe848.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0020d018(int param_1,int param_2,int param_3)
{
  int *piVar1;
  
  if (param_3 < 10) {
    piVar1 = (int *)(param_1 + param_3 * 0x20);
    do {
      if (param_2 == *piVar1) {
        return 1;
      }
      param_3 = param_3 + 1;
      piVar1 = piVar1 + 8;
    } while (param_3 < 10);
  }
  return 0;
}
