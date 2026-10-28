/* HSTMATCH module=hstp_trans_main.prx start=0x0011d550 end=0x0011d5e4 symbol=FUN_0011d550 lang=c99 */
/* Clone of src/eboot/FUN_00113314.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b0fbc;
extern u8 DAT_003b0fc8;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();

int * FUN_0011d550(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[0x1f] = (int)&DAT_003b0fbc;
    *(u8 **)*param_1 = &DAT_003b0fc8;
    piVar1 = param_1 + 0x20;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[0x20] = (int)&DAT_003b0a68;
      FUN_0010642c(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
