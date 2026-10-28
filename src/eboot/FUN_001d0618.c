/* HSTMATCH module=EBOOT.BIN start=0x001d0618 end=0x001d0624 symbol=FUN_001d0618 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b8cc();

void FUN_001d0618(int param_1,u32 param_2)
{
  FUN_0010b8cc(*(u32 *)(param_1 + 0x58),param_2,0);
}
