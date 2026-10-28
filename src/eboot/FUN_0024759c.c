/* HSTMATCH module=EBOOT.BIN start=0x0024759c end=0x002475bc symbol=FUN_0024759c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0024759c(char *param_1,int param_2)
{
  if (*(int *)(param_1 + 0x3c) != param_2) {
    *(int *)(param_1 + 0x3c) = param_2;
    *(u8 *)(param_1 + 0x464) = 1;
  }
}
