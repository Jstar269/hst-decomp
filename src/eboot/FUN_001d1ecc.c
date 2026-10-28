/* HSTMATCH module=EBOOT.BIN start=0x001d1ecc end=0x001d1f04 symbol=FUN_001d1ecc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();

void FUN_001d1ecc(void)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
}
