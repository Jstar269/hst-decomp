/* HSTMATCH module=EBOOT.BIN start=0x0001efdc end=0x0001f004 symbol=FUN_0001efdc lang=c99 */
/* Clone of src/sharing_main/FUN_0001ebb4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002b7a88();
extern void FUN_002b7a98();

u32 FUN_0001efdc(void)
{
  FUN_002b7a88(1);
  FUN_002b7a98(0);
  return 1;
}
