/* HSTMATCH module=EBOOT.BIN start=0x001252d0 end=0x001252fc symbol=FUN_001252d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340284; /* host object */
extern int FUN_00131a78();

/* Returns the host's value for query 6 as a float. */
float FUN_001252d0(void)
{
  int value;
  
  value = FUN_00131a78(DAT_00340284,6);
  return (float)value;
}
