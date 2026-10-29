/* HSTMATCH module=EBOOT.BIN start=0x000d5dc8 end=0x000d5dec symbol=FUN_000d5dc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64d) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0000430c();

/* Comparator: true when FUN_0000430c reports a before b; the first argument (the comparator object) is unused. */
bool FUN_000d5dc8(u32 self,u32 a,u32 b)
{
  int result;
  
  result = FUN_0000430c(a,b);
  return result < 0;
}
