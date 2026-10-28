/* HSTMATCH module=EBOOT.BIN start=0x0026366c end=0x002636d8 symbol=FUN_0026366c lang=c99 */
/* Clone of src/eboot/FUN_001066ac.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309380;
extern u8 DAT_00309a54;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

u32 * FUN_0026366c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309a54);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00309380);
      FUN_00102ea4(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
