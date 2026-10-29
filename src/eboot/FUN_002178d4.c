/* HSTMATCH module=EBOOT.BIN start=0x002178d4 end=0x00217910 symbol=FUN_002178d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_00217910();
extern void FUN_0021791c();
extern void FUN_00217928();
extern void FUN_00217934();

/* Stop all four blocks. */
void FUN_002178d4(Animator *self)
{
  FUN_00217910();
  FUN_0021791c(self);
  FUN_00217928(self);
  FUN_00217934(self);
}
