/* HSTMATCH module=hstp_trans_main.prx start=0x001236c0 end=0x0012376c symbol=FUN_001236c0 lang=c99 */
/* Clone of src/eboot/FUN_001184ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b12c8;
extern u32 DAT_003e47a0;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00123a9c();
extern void FUN_001244f0();
extern int FUN_00127df0();
extern int FUN_001281a0();

u32 * FUN_001236c0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b12c8);
    DAT_003e47a0 = 0;
    FUN_001244f0();
    FUN_00123a9c(param_1);
    puVar1 = param_1 + 0xbe;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001281a0(puVar1,0);
    }
    puVar1 = param_1 + 0xb8;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00127df0(puVar1,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
