/* HSTMATCH module=EBOOT.BIN start=0x001b3b4c end=0x001b3b64 symbol=FUN_001b3b4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e5950;
extern void FUN_001b06d4();

void FUN_001b3b4c(u32 *param_1)
{
  FUN_001b06d4(*param_1,&DAT_002e5950,8,0);
}
