/* HSTMATCH module=hstp_trans_main.prx start=0x0015e54c end=0x0015e5d4 symbol=FUN_0015e54c lang=c99 */
/* Clone of src/eboot/FUN_001523fc.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b16d8;
extern u8 DAT_003b1eec;
extern void FUN_000009e4();
extern void FUN_00000a00();

u32 * FUN_0015e54c(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1eec);
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      param_1[4] = 0;
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b16d8);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
