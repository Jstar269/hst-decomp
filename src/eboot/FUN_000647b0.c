/* HSTMATCH module=EBOOT.BIN start=0x000647b0 end=0x00064820 symbol=FUN_000647b0 lang=c99 */
/* Clone of src/sharing_main/FUN_00065674.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307124;
extern u8 DAT_00307148;
extern void FUN_000009e4();
extern void FUN_00000a00();

u32 * FUN_000647b0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307124);
    FUN_000009e4(param_1[1]);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00307148);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
