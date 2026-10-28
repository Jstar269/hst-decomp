/* HSTMATCH module=EBOOT.BIN start=0x000017b0 end=0x0000180c symbol=FUN_000017b0 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306ef8;
extern u8 DAT_00306ed8;
extern void FUN_00000a00();

u32 * FUN_000017b0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00306ef8);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00306ed8);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
