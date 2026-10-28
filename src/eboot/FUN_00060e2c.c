/* HSTMATCH module=EBOOT.BIN start=0x00060e2c end=0x00060e7c symbol=FUN_00060e2c lang=c99 */
/* Clone of src/sharing_main/FUN_00061cb0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030707c;
extern u32 * FUN_000607b8();

u32 * FUN_00060e2c(u32 *param_1)
{
  FUN_000607b8();
  *param_1 = (unsigned int)(&DAT_0030707c);
  param_1[0x20] = 0x42340000;
  param_1[0x21] = 0x3e4ccccd;
  param_1[0x22] = 0x447a0000;
  return param_1;
}
