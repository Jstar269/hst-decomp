/* HSTMATCH module=EBOOT.BIN start=0x00118b4c end=0x00118b8c symbol=FUN_00118b4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00118b8c();
extern u32 FUN_00118cc0();

u32 FUN_00118b4c(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00118cc0(param_1);
  FUN_00118b8c(param_1,param_3);
  return param_1;
}
