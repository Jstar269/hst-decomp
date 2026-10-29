/* HSTMATCH module=EBOOT.BIN start=0x00225d40 end=0x00225d54 symbol=FUN_00225d40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern void FUN_00220768();

void FUN_00225d40(ModeObj *self,u32 arg1,u32 arg2)
{
  FUN_00220768(self->parts->part1c,arg1,0,arg2);
}
