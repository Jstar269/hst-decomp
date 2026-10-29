/* HSTMATCH module=EBOOT.BIN start=0x001d6aa0 end=0x001d6ab0 symbol=FUN_001d6aa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

/* Reset the two flag bytes of the object and call FUN_00103628(self, 1). */
void FUN_001d6aa0(u8 *self)
{
  self[0x54] = 0;
  self[0x55] = 0;
  FUN_00103628(self,1);
}
