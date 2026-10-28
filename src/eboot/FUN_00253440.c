/* HSTMATCH module=EBOOT.BIN start=0x00253440 end=0x0025346c symbol=FUN_00253440 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0025346c();

int FUN_00253440(int param_1)
{
  *(u8 *)(param_1 + 0x34) = 0;
  FUN_0025346c();
  return param_1;
}
