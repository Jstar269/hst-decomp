/* HSTMATCH module=EBOOT.BIN start=0x001b71c4 end=0x001b7210 symbol=FUN_001b71c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_000622d4();
extern void FUN_001b3650();
extern void FUN_001b3e2c();
extern void FUN_001b41c8();

void FUN_001b71c4(void)
{
  FUN_000622d4(3,0x80,0x80,0);
  FUN_001b3e2c((int *)&DAT_0034179c);
  FUN_001b41c8((int *)&DAT_0034179c);
  FUN_001b3650((int *)&DAT_0034179c);
}
