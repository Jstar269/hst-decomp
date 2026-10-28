/* HSTMATCH module=hstp_trans_main.prx start=0x001317c8 end=0x00131868 symbol=FUN_001317c8 lang=c99 */
/* Clone of src/eboot/FUN_00126558.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b1310;
extern void FUN_00000a00();
extern void FUN_002c7680();
extern void FUN_002c76a0();
extern void FUN_002c7ba0();

u32 * FUN_001317c8(u32 *param_1,short param_2)
{
  int iVar1;
  u32 uVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1310);
    if ((u8 *)param_1[5] != (u8 *)0x0) {
      *(u8 *)param_1[5] = 1;
    }
    iVar1 = param_1[1];
    if (iVar1 >= 1) {
      FUN_002c7ba0(param_1[3],0);
      FUN_002c7680(param_1[1],0);
      FUN_002c76a0(param_1[1]);
    }
    uVar2 = param_1[3];
    FUN_002c7ba0(uVar2,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
