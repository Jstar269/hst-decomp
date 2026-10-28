/* HSTMATCH module=EBOOT.BIN start=0x0022995c end=0x0022999c symbol=FUN_0022995c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00229d98();

void FUN_0022995c(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_00229d98(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
