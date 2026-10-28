/* HSTMATCH module=EBOOT.BIN start=0x001b8d2c end=0x001b8d38 symbol=FUN_001b8d2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b3640();

void FUN_001b8d2c(void)
{
  FUN_001b3640((int *)&DAT_0034179c);
}
