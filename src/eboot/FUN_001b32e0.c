/* HSTMATCH module=EBOOT.BIN start=0x001b32e0 end=0x001b32f8 symbol=FUN_001b32e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b0ef8();

void FUN_001b32e0(u32 *param_1,int param_2)
{
  FUN_001b0ef8(*param_1,param_2 + 0x27,0,0,0);
}
