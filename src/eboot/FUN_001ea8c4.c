/* HSTMATCH module=EBOOT.BIN start=0x001ea8c4 end=0x001ea8d0 symbol=FUN_001ea8c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001ea8c4(int *param_1,u8 param_2)
{
  *(u8 *)(*param_1 + 0x419) = param_2;
}
