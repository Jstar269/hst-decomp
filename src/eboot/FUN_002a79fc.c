/* HSTMATCH module=EBOOT.BIN start=0x002a79fc end=0x002a7a08 symbol=FUN_002a79fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b8cc();

void FUN_002a79fc(int param_1,u32 param_2)
{
  FUN_0010b8cc(*(u32 *)(param_1 + 0x358),param_2,0);
}
