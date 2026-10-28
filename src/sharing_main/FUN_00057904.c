/* HSTMATCH module=hstp_trans_main.prx start=0x00057904 end=0x000579bc symbol=FUN_00057904 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02c4;
extern void FUN_00000a00();
extern void FUN_00057bdc();
extern void FUN_00057fa0();
extern void FUN_00058384();
extern void FUN_00058b84();
extern int * FUN_0005a3d8();
extern int * FUN_0005a5ac();
extern u32 * FUN_0005f8ec();

u32 * FUN_00057904(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b02c4);
    FUN_00058b84(param_1,0);
    FUN_00058384(param_1);
    FUN_00057fa0(param_1);
    FUN_00057bdc(param_1);
    puVar1 = param_1 + 0x5d;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0005a5ac(puVar1,0);
    }
    puVar1 = param_1 + 0x38;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0005a3d8(puVar1,0);
    }
    FUN_0005f8ec(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
