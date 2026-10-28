/* HSTMATCH module=EBOOT.BIN start=0x00117d38 end=0x00117d70 symbol=FUN_00117d38 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_0008ac88();

void FUN_00117d38(void)
{
  FUN_0008ac88(DAT_003386b0);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
}
