/* HSTMATCH module=hstp_trans_main.prx start=0x000d8a24 end=0x000d8acc symbol=FUN_000d8a24 lang=c99 */
/* Clone of src/eboot/FUN_000d4d34.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0718;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int FUN_000541d8();
extern int FUN_000569f4();
extern void FUN_00057904();

u32 * FUN_000d8a24(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0718);
    if (param_1[0xf] != 0) {
      FUN_000541d8(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    iVar1 = param_1[0x10];
    if (iVar1 != 0) {
      FUN_000569f4(iVar1,1);
      param_1[0x10] = 0;
    }
    FUN_00000788(param_1 + 0x14,FUN_00057904,0x1b0,4);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
