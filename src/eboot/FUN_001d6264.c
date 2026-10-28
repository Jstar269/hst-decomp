/* HSTMATCH module=EBOOT.BIN start=0x001d6264 end=0x001d6280 symbol=FUN_001d6264 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d6264(int param_1,u32 *param_2)
{
  if (param_2 != (u32 *)0x0) {
    *(u32 *)(param_1 + 8) = *param_2;
  }
  *(u32 *)(param_1 + 4) = 0;
}
