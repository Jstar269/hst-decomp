/* HSTMATCH module=EBOOT.BIN start=0x000efdec end=0x000efe28 symbol=FUN_000efdec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005f1e8();
extern void FUN_001031e8();

void FUN_000efdec(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_001031e8();
    FUN_0005f1e8(*(u32 *)(param_1 + 0x90),*(u32 *)(param_1 + 0x9c));
  }
}
