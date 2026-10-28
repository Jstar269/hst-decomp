/* HSTMATCH module=EBOOT.BIN start=0x001b39f4 end=0x001b3a0c symbol=FUN_001b39f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e5918;
extern void FUN_001b06d4();

void FUN_001b39f4(u32 *param_1)
{
  FUN_001b06d4(*param_1,&DAT_002e5918,9,0);
}
