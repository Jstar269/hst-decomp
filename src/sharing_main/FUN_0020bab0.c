/* HSTMATCH module=hstp_trans_main.prx start=0x0020bab0 end=0x0020bc3c symbol=FUN_0020bab0 lang=c99 */
/* Clone of src/eboot/FUN_001fd2e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0388;
extern u8 DAT_003b287c;
extern u32 DAT_003f3474;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000658cc();
extern int FUN_0006778c();
extern int FUN_0020e490();
extern int FUN_00210214();
extern void FUN_00212bfc();
extern void FUN_0005c688();

u32 * FUN_0020bab0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b287c);
    FUN_00212bfc();
    DAT_003f3474 = 0;
    if ((char *)param_1 + 0x12c4 != (char *)0) {
      puVar1 = param_1 + 0x4b9;
      param_1[0x4b1] = (unsigned int)(&DAT_003b0388);
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4b5;
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x4b1,0);
    }
    if ((char *)param_1 + 0x1294 != (char *)0) {
      puVar1 = param_1 + 0x4ad;
      param_1[0x4a5] = (unsigned int)(&DAT_003b0388);
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4a9;
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x4a5,0);
    }
    FUN_00210214((int)(param_1 + 0x494),-1);
    FUN_00000788((int)(param_1 + 0x334),FUN_0005c688,0x2c0,2);
    FUN_0020e490((int)(param_1 + 0x32),-1);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
