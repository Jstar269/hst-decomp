/* HSTMATCH module=EBOOT.BIN start=0x002ade80 end=0x002adec4 symbol=FUN_002ade80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b5d0;
extern void FUN_00000a00();

/* Deleting destructor: clears the global pointer and frees the object when flag > 0. */
int FUN_002ade80(int self,short flag)
{
  if ((self != 0) && (DAT_0034b5d0 = 0, 0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
