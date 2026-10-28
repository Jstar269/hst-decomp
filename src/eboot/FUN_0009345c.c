/* HSTMATCH module=EBOOT.BIN start=0x0009345c end=0x00093484 symbol=FUN_0009345c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000550c8();

void FUN_0009345c(int param_1,u32 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_000550c8(*(int *)(param_1 + 0x58),param_2);
  }
}
