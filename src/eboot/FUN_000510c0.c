/* HSTMATCH module=EBOOT.BIN start=0x000510c0 end=0x00051118 symbol=FUN_000510c0 lang=c99 */
/* Clone of src/sharing_main/FUN_000519d4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fc8;
extern void FUN_00000a00();
extern void FUN_00051358();

u32 * FUN_000510c0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00306fc8);
    FUN_00051358();
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
