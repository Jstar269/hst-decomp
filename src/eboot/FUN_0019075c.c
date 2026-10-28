/* HSTMATCH module=EBOOT.BIN start=0x0019075c end=0x00190764 symbol=FUN_0019075c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0018f238();

void FUN_0019075c(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  FUN_0018f238(*(int **)(param_1 + 0x3c),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
}
