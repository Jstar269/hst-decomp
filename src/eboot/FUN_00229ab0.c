/* HSTMATCH module=EBOOT.BIN start=0x00229ab0 end=0x00229af0 symbol=FUN_00229ab0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022a124();

void FUN_00229ab0(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_0022a124(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
