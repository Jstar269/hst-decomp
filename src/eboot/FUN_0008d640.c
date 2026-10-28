/* HSTMATCH module=EBOOT.BIN start=0x0008d640 end=0x0008d650 symbol=FUN_0008d640 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0008d640(int param_1,int param_2,u16 param_3)
{
  *(u16 *)(param_1 + param_2 * 2) = param_3;
}
