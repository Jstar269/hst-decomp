/* HSTMATCH module=EBOOT.BIN start=0x00047898 end=0x000478ac symbol=FUN_00047898 lang=c99 */
/* Clone of src/sharing_main/FUN_00047d1c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d0220;

bool FUN_00047898(void)
{
  return DAT_002d0220 == 0;
}
