/* HSTMATCH module=EBOOT.BIN start=0x001b3b34 end=0x001b3b4c symbol=FUN_001b3b34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e593c;
extern void FUN_001b06d4();

void FUN_001b3b34(u32 *param_1)
{
  FUN_001b06d4(*param_1,&DAT_002e593c,5,0);
}
