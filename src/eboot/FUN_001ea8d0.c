/* HSTMATCH module=EBOOT.BIN start=0x001ea8d0 end=0x001ea8dc symbol=FUN_001ea8d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001ea8d0(int *param_1,u8 param_2)
{
  *(u8 *)(*param_1 + 0x424) = param_2;
}
