/* HSTMATCH module=EBOOT.BIN start=0x001184ec end=0x00118598 symbol=FUN_001184ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307ffc;
extern u32 DAT_0033b460;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001188c8();
extern void FUN_0011931c();
extern int FUN_0011cc1c();
extern int FUN_0011cfcc();

u32 * FUN_001184ec(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307ffc);
    DAT_0033b460 = 0;
    FUN_0011931c();
    FUN_001188c8(param_1);
    puVar1 = param_1 + 0xbe;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0011cfcc(puVar1,0);
    }
    puVar1 = param_1 + 0xb8;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0011cc1c(puVar1,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
