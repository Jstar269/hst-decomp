/* HSTMATCH module=hstp_trans_main.prx start=0x0013da04 end=0x0013dbf0 symbol=FUN_0013da04 lang=c99 */
/* Clone of src/eboot/FUN_001323e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b14d8;
extern u8 DAT_003b14f4;
extern u32 DAT_003e95e0;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000550a0();
extern int * FUN_0006026c();
extern int * FUN_000ed9b8();
extern void FUN_0013dbf0();
extern int * FUN_00147f54();
extern int * FUN_00148068();
extern int * FUN_00148114();
extern int * FUN_001481c0();
extern int * FUN_0014826c();
extern int * FUN_00148318();
extern int * FUN_001483d4();
extern int * FUN_00148490();
extern int * FUN_0014854c();
extern int * FUN_001485f8();
extern u32 * FUN_0014be3c();

u32 * FUN_0013da04(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b14d8);
    param_1[0x10] = (unsigned int)(&DAT_003b14f4);
    FUN_0013dbf0();
    puVar1 = param_1 + 0x514;
    DAT_003e95e0 = 0;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001485f8(puVar1,0);
    }
    puVar1 = param_1 + 0x50c;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000ed9b8(puVar1,0);
    }
    puVar1 = param_1 + 0x502;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0006026c(puVar1,0);
    }
    puVar1 = param_1 + 0x4ff;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000550a0(puVar1,0);
    }
    puVar1 = param_1 + 0x4fc;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00147f54(puVar1,0);
    }
    puVar1 = param_1 + 0x4f9;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0014854c(puVar1,0);
    }
    puVar1 = param_1 + 0x4f6;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00148490(puVar1,0);
    }
    puVar1 = param_1 + 0x4f3;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001483d4(puVar1,0);
    }
    puVar1 = param_1 + 0x4ef;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00148318(puVar1,0);
    }
    puVar1 = param_1 + 0x4ec;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0014826c(puVar1,0);
    }
    puVar1 = param_1 + 0x4e9;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001481c0(puVar1,0);
    }
    puVar1 = param_1 + 0x4e6;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00148114(puVar1,0);
    }
    puVar1 = param_1 + 0x4e3;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00148068(puVar1,0);
    }
    FUN_0014be3c(param_1 + 0x10,0);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
