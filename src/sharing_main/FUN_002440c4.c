/* HSTMATCH module=hstp_trans_main.prx start=0x002440c4 end=0x0024414c symbol=FUN_002440c4 lang=c99 */
/* Clone of src/eboot/FUN_00233fc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * DAT_003f3994;
extern u8 DAT_003f39a8;
extern void FUN_00243618();
extern void FUN_00244258();
extern void FUN_0024476c();

void FUN_002440c4(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  bool bVar1;
  int iVar2;
  
  if (DAT_003f3994 != (int *)0x0) {
    FUN_00243618(DAT_003f3994,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    iVar2 = DAT_003f3994[3];
    bVar1 = true;
    if ((iVar2 != 6) && (iVar2 != 7)) {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_00244258((int *)&DAT_003f39a8,2);
    }
    else if (iVar2 == 9) {
      FUN_0024476c((int *)&DAT_003f39a8);
    }
  }
}
