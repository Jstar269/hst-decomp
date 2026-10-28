/* HSTMATCH module=EBOOT.BIN start=0x0006596c end=0x000659c8 symbol=FUN_0006596c lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003070dc;
extern u8 DAT_00307148;
extern void FUN_00000a00();

u32 * FUN_0006596c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003070dc);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00307148);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
