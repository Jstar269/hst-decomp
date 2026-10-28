/* HSTMATCH module=EBOOT.BIN start=0x000039e8 end=0x00003a44 symbol=FUN_000039e8 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306f50;
extern void FUN_00000a00();
extern u32 * FUN_00003a44();

u32 * FUN_000039e8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00306f50);
    FUN_00003a44(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
