/* HSTMATCH module=EBOOT.BIN start=0x00216de8 end=0x00216e00 symbol=FUN_00216de8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Half of `value`, rounded up. */
int FUN_00216de8(u32 value)
{
  int half;
  
  half = (int)value >> 1;
  if ((value & 1) != 0) {
    half = half + 1;
  }
  return half;
}
