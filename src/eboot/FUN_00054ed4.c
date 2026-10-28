/* HSTMATCH module=EBOOT.BIN start=0x00054ed4 end=0x00054f08 symbol=FUN_00054ed4 lang=c99 */
/* Clone of src/sharing_main/FUN_000518d4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fd4;
extern void FUN_00054fb0();

u32 * FUN_00054ed4(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00306fd4);
  FUN_00054fb0();
  return param_1;
}
