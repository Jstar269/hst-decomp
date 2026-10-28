/* HSTMATCH module=hstp_trans_main.prx start=0x0011d5e4 end=0x0011d678 symbol=FUN_0011d5e4 lang=c99 */
/* Clone of src/eboot/FUN_001133a8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b100c;
extern u8 DAT_003b101c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();

int * FUN_0011d5e4(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b100c;
    *(u8 **)*param_1 = &DAT_003b101c;
    piVar1 = param_1 + 4;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[4] = (int)&DAT_003b0a68;
      FUN_0010642c(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
