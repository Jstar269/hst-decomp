/* HSTMATCH module=EBOOT.BIN start=0x0001cbd0 end=0x0001cbfc symbol=FUN_0001cbd0 lang=c99 */
/* Clone of src/sharing_main/FUN_0001c81c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc88;
extern u32 DAT_0030fc04;

void FUN_0001cbd0(int param_1)
{
  if (DAT_0030fc04 == 0) {
    DAT_002cfc88 = param_1 + 0x7fffU & 0xffff8000;
  }
}
