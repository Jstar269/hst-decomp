/* HSTMATCH module=hstp_trans_main.prx start=0x00049200 end=0x00049280 symbol=FUN_00049200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0264;
extern u8 DAT_003b0270;
extern void FUN_00000a00();
extern u32 * FUN_00057904();

int * FUN_00049200(int *param_1,int param_2)
{
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b0264;
    *(u8 **)*param_1 = &DAT_003b0270;
    *(int *)(*param_1 + 0x1b0) = (int)(param_1 + 0xc) - *param_1;
    if (param_2 != 0) {
      FUN_00057904(param_1 + 0xc,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
