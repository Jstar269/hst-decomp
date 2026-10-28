/* HSTMATCH module=EBOOT.BIN start=0x000462a0 end=0x00046300 symbol=FUN_000462a0 lang=c99 */
/* Clone of src/sharing_main/FUN_000463a0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

u32 * FUN_000462a0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    if ((*param_1 & 1) != 0) {
      FUN_00000a00(param_1[2]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
