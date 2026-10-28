/* HSTMATCH module=hstp_trans_main.prx start=0x00120d7c end=0x00120e40 symbol=FUN_00120d7c lang=c99 */
/* Clone of src/eboot/FUN_00115e60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b11d0;
extern u8 DAT_003b11e4;
extern u8 DAT_003b122c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern int * FUN_0010d2d4();

int * FUN_00120d7c(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b11d0;
    *(u8 **)*param_1 = &DAT_003b11e4;
    *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
    if ((param_2 != 0) && (param_1 + 0x1c != (int *)0x0)) {
      piVar1 = param_1 + 100;
      param_1[0x1c] = (int)&DAT_003b122c;
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_0010d2d4(piVar1,0);
      }
      if (param_1 + 0x1c != (int *)0x0) {
        param_1[0x1c] = (int)&DAT_003b0a68;
        FUN_0010642c(param_1 + 0x1c,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
