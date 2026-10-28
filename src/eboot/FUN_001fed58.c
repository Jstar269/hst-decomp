/* HSTMATCH module=EBOOT.BIN start=0x001fed58 end=0x001fed8c symbol=FUN_001fed58 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003313c4;
extern void FUN_0005c900();
extern void FUN_0005ca5c();

void FUN_001fed58(void)
{
  FUN_0005ca5c(DAT_003313c4,0);
  FUN_0005c900(DAT_003313c4,0);
}
