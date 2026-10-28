/* HSTMATCH module=EBOOT.BIN start=0x001b5740 end=0x001b574c symbol=FUN_001b5740 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b39f4();

void FUN_001b5740(void)
{
  FUN_001b39f4((u32 *)&DAT_0034179c);
}
