/* HSTMATCH module=EBOOT.BIN start=0x0001efac end=0x0001efc0 symbol=FUN_0001efac lang=c99 */
/* Clone of src/sharing_main/FUN_0001eb84.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern u8 DAT_0030fc40;

void FUN_0001efac(void)
{
  DAT_002cfc8c = (unsigned int)(&DAT_0030fc40);
}
