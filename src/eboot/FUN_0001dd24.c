/* HSTMATCH module=EBOOT.BIN start=0x0001dd24 end=0x0001dd58 symbol=FUN_0001dd24 lang=c99 */
/* Clone of src/sharing_main/FUN_0001d970.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001dd58();
extern void FUN_0001dfa0();

void FUN_0001dd24(u32 param_1)
{
  FUN_0001dd58();
  FUN_0001dfa0(param_1,1,0);
}
