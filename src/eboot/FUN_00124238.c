/* HSTMATCH module=EBOOT.BIN start=0x00124238 end=0x00124268 symbol=FUN_00124238 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001240fc();

void FUN_00124238(int param_1)
{
  FUN_001240fc(param_1,1,0);
  *(u32 *)(param_1 + 0x68) = 0;
}
