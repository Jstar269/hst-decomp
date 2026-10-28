/* HSTMATCH module=hstp_trans_main.prx start=0x0010642c end=0x001064bc symbol=FUN_0010642c lang=c99 */
/* Clone of src/eboot/FUN_00100b24.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e38;
extern void FUN_00000a00();
extern int * FUN_001019c0();
extern int * FUN_00101a28();
extern void FUN_001064bc();

u32 * FUN_0010642c(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0e38);
    FUN_001064bc();
    puVar1 = param_1 + 4;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00101a28(puVar1,0);
    }
    puVar1 = param_1 + 1;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001019c0(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
