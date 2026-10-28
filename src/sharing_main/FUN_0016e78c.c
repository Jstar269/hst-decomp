/* HSTMATCH module=hstp_trans_main.prx start=0x0016e78c end=0x0016e864 symbol=FUN_0016e78c lang=c99 */
/* Clone of src/eboot/FUN_00162200.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea848;
extern u32 DAT_003ea84c;
extern u32 DAT_003ea850;
extern void FUN_000006e8();
extern void FUN_00000a00();
extern int * FUN_00171914();
extern int * FUN_00171a30();
extern void FUN_0016e864();

int FUN_0016e78c(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    if (param_1 == DAT_003ea848) {
      if (DAT_003ea84c != 0) {
        FUN_000006e8(DAT_003ea84c,FUN_0016e78c);
        DAT_003ea84c = 0;
      }
      if (DAT_003ea850 != 0) {
        FUN_000006e8(DAT_003ea850,FUN_0016e864);
        DAT_003ea850 = 0;
      }
    }
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00171a30(iVar1,0);
    }
    if ((param_1 != 0) && (0 != param_1)) {
      FUN_00171914(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
