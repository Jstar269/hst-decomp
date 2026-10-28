/* HSTMATCH module=EBOOT.BIN start=0x001b322c end=0x001b3244 symbol=FUN_001b322c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e598c;
extern void FUN_001b06d4();

void FUN_001b322c(u32 *param_1)
{
  FUN_001b06d4(*param_1,&DAT_002e598c,0x1a,0);
}
