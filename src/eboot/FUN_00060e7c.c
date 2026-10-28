/* HSTMATCH module=EBOOT.BIN start=0x00060e7c end=0x00060ed8 symbol=FUN_00060e7c lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030707c;
extern u8 DAT_0030708c;
extern void FUN_00000a00();

u32 * FUN_00060e7c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030707c);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030708c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
