/* HSTMATCH module=EBOOT.BIN start=0x00190290 end=0x001902d0 symbol=FUN_00190290 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003e04();
extern u32 * FUN_00190880();

int FUN_00190290(int param_1,int param_2)
{
  FUN_00003e04();
  FUN_00190880(param_1 + 0xc,param_2 + 0xc);
  return param_1;
}
