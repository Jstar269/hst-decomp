/* HSTMATCH module=EBOOT.BIN start=0x001b9014 end=0x001b9020 symbol=FUN_001b9014 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b36f4();

void FUN_001b9014(void)
{
  FUN_001b36f4((int *)&DAT_0034179c);
}
