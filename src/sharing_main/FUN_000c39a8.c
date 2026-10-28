/* HSTMATCH module=hstp_trans_main.prx start=0x000c39a8 end=0x000c3a2c symbol=FUN_000c39a8 lang=c99 */
/* Clone of src/eboot/FUN_000c0308.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06c8;
extern void FUN_00000a00();
extern void FUN_002c7680();
extern void FUN_002c76a0();

u32 * FUN_000c39a8(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06c8);
    if ((u8 *)param_1[4] != (u8 *)0x0) {
      *(u8 *)param_1[4] = 1;
    }
    iVar1 = param_1[1];
    if (0 < iVar1) {
      FUN_002c7680(iVar1,0);
      FUN_002c76a0(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
