/* HSTMATCH module=EBOOT.BIN start=0x0003cb08 end=0x0003cb18 symbol=FUN_0003cb08 lang=c99 */
/* Clone of src/sharing_main/FUN_0003cb18.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0003d228();

void FUN_0003cb08(int param_1)
{
  FUN_0003d228(*(u32 *)(param_1 + 0x81c),0,0);
}
