/* HSTMATCH module=EBOOT.BIN start=0x00055e48 end=0x00055e98 symbol=FUN_00055e48 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_000560a0();

/* Deleting destructor of the state holder: releases the menu (FUN_000560a0), then frees the object when flags is positive. */
SelectionState *FUN_00055e48(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_000560a0(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
