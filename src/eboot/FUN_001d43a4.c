/* HSTMATCH module=EBOOT.BIN start=0x001d43a4 end=0x001d43b4 symbol=FUN_001d43a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001d43a4(int param_1)
{
  return (*(u16 *)(param_1 + 0xe) & 3) != 0;
}
