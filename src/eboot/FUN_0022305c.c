/* HSTMATCH module=EBOOT.BIN start=0x0022305c end=0x00223094 symbol=FUN_0022305c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_0022305c(int param_1)
{
  FUN_00103628(param_1,1);
  *(u8 *)(param_1 + 0x58) = 1;
  *(u32 *)(param_1 + 0x60) = 0xffffffff;
}
