/* HSTMATCH module=EBOOT.BIN start=0x0025b050 end=0x0025b090 symbol=FUN_0025b050 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_0025b090();
extern u32 FUN_0025b1c4();

u32 FUN_0025b050(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_0025b1c4(param_1);
  FUN_0025b090(param_1,param_3);
  return param_1;
}
