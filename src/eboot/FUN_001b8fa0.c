/* HSTMATCH module=EBOOT.BIN start=0x001b8fa0 end=0x001b8fac symbol=FUN_001b8fa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b36ec();

void FUN_001b8fa0(void)
{
  FUN_001b36ec((int *)&DAT_0034179c);
}
