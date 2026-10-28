/* HSTMATCH module=EBOOT.BIN start=0x00092e38 end=0x00092e50 symbol=FUN_00092e38 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00092e38(int param_1)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    *(u8 *)(*(int *)(param_1 + 0x58) + 0x170) = 0;
  }
}
