/* HSTMATCH module=EBOOT.BIN start=0x0021aa6c end=0x0021aabc symbol=FUN_0021aa6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_0021ab00();

/* Deleting destructor of the state holder: releases the menu (FUN_0021ab00), then frees the object when flags is positive. */
SelectionState *FUN_0021aa6c(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_0021ab00(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
