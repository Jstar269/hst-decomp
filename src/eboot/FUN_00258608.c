/* HSTMATCH module=EBOOT.BIN start=0x00258608 end=0x00258630 symbol=FUN_00258608 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00258608(int param_1,int param_2,int param_3)
{
  return *(u32 *)(param_1 + param_2 * 0xa4 + param_3 * 4);
}
