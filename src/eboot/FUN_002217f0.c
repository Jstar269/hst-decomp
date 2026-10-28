/* HSTMATCH module=EBOOT.BIN start=0x002217f0 end=0x0022181c symbol=FUN_002217f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_002217f0(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
