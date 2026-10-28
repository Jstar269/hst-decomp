/* HSTMATCH module=hstp_trans_main.prx start=0x0005f8ec end=0x0005f988 symbol=FUN_0005f8ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0318;
extern void FUN_00000a00();
extern int * FUN_00055a6c();
extern void FUN_0005fd08();
extern int * FUN_0006026c();
extern int * FUN_00060478();

u32 * FUN_0005f8ec(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0318);
    FUN_0005fd08();
    puVar1 = param_1 + 0x2d;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0006026c(puVar1,0);
    }
    puVar1 = param_1 + 0x2a;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00060478(puVar1,0);
    }
    FUN_00055a6c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
