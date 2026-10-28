/* HSTMATCH module=EBOOT.BIN start=0x0027929c end=0x002792a8 symbol=FUN_0027929c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b8cc();

void FUN_0027929c(int param_1,u32 param_2)
{
  FUN_0010b8cc(*(u32 *)(param_1 + 0x474),param_2,0);
}
