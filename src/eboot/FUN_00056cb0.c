/* HSTMATCH module=EBOOT.BIN start=0x00056cb0 end=0x00056d68 symbol=FUN_00056cb0 lang=c99 */
/* Clone of src/sharing_main/FUN_00057904.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306ff8;
extern void FUN_00000a00();
extern void FUN_00056f88();
extern void FUN_0005734c();
extern void FUN_00057730();
extern void FUN_00057f30();
extern int * FUN_000596f4();
extern int * FUN_000598c8();
extern u32 * FUN_0005eafc();

u32 * FUN_00056cb0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00306ff8);
    FUN_00057f30(param_1,0);
    FUN_00057730(param_1);
    FUN_0005734c(param_1);
    FUN_00056f88(param_1);
    puVar1 = param_1 + 0x5d;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000598c8(puVar1,0);
    }
    puVar1 = param_1 + 0x38;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000596f4(puVar1,0);
    }
    FUN_0005eafc(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
