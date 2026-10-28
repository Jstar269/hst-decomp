/* HSTMATCH module=EBOOT.BIN start=0x0005eafc end=0x0005eb98 symbol=FUN_0005eafc lang=c99 */
/* Clone of src/sharing_main/FUN_0005f8ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030704c;
extern void FUN_00000a00();
extern int * FUN_00054f4c();
extern void FUN_0005ef18();
extern int * FUN_0005f47c();
extern int * FUN_0005f688();

u32 * FUN_0005eafc(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030704c);
    FUN_0005ef18();
    puVar1 = param_1 + 0x2d;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0005f47c(puVar1,0);
    }
    puVar1 = param_1 + 0x2a;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0005f688(puVar1,0);
    }
    FUN_00054f4c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
