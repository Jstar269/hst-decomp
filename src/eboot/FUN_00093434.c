/* HSTMATCH module=EBOOT.BIN start=0x00093434 end=0x0009345c symbol=FUN_00093434 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00055044();

void FUN_00093434(int param_1,u32 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00055044(*(int *)(param_1 + 0x58),param_2);
  }
}
