/* HSTMATCH module=EBOOT.BIN start=0x0023165c end=0x0023167c symbol=FUN_0023165c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002f3668;
extern u8 DAT_002f366c;

void FUN_0023165c(int param_1)
{
  DAT_002f3668 = *(u32 *)(&DAT_002f366c + param_1 * 4);
}
