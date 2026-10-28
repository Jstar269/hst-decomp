/* HSTMATCH module=hstp_trans_main.prx start=0x001206a4 end=0x0012071c symbol=FUN_001206a4 lang=c99 */
/* Clone of src/eboot/FUN_00115788.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0ea4;
extern void FUN_00000a00();
extern u32 * FUN_001087a8();
extern int * FUN_001212c4();

u32 * FUN_001206a4(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    puVar1 = param_1 + 0x23;
    *param_1 = (unsigned int)(&DAT_003b0ea4);
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001212c4(puVar1,0);
    }
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
