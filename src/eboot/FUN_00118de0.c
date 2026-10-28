/* HSTMATCH module=EBOOT.BIN start=0x00118de0 end=0x00118e20 symbol=FUN_00118de0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00118e20();
extern u32 FUN_00118f54();

u32 FUN_00118de0(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00118f54(param_1);
  FUN_00118e20(param_1,param_3);
  return param_1;
}
