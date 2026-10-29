/* HSTMATCH module=EBOOT.BIN start=0x002ade24 end=0x002ade48 symbol=FUN_002ade24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0001100c();

/* True when the two 16-byte blocks are equal. */
bool FUN_002ade24(u32 a,u32 b)
{
  int diff;
  
  diff = FUN_0001100c(a,b,0x10);
  return diff == 0;
}
