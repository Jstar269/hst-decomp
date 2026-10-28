/* HSTMATCH module=EBOOT.BIN start=0x00050fc0 end=0x00050ff4 symbol=FUN_00050fc0 lang=c99 */
/* Clone of src/sharing_main/FUN_000518d4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fc8;
extern void FUN_00051118();

u32 * FUN_00050fc0(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00306fc8);
  FUN_00051118();
  return param_1;
}
