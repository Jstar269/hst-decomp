/* HSTMATCH module=EBOOT.BIN start=0x0021b79c end=0x0021b7d4 symbol=FUN_0021b79c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

/* Puts the screen in its finished state: finished flag set, counter idle (-1). */
void FUN_0021b79c(int self)
{
  FUN_00103628(self,1);
  *(u8 *)(self + 0x54) = 1;
  *(u32 *)(self + 100) = 0xffffffff;
}
