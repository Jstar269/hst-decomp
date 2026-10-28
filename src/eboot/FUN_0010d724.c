/* HSTMATCH module=EBOOT.BIN start=0x0010d724 end=0x0010d74c symbol=FUN_0010d724 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00102370();

void FUN_0010d724(int param_1)
{
  FUN_00102370();
  *(u32 *)(param_1 + 0xf8) = 0;
}
