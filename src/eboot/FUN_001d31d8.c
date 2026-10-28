/* HSTMATCH module=EBOOT.BIN start=0x001d31d8 end=0x001d31e8 symbol=FUN_001d31d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4074();

void FUN_001d31d8(void)
{
  FUN_001b4074((int *)&DAT_0034179c,1);
}
