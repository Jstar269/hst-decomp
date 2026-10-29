/* HSTMATCH module=EBOOT.BIN start=0x0004ae08 end=0x0004ae58 symbol=FUN_0004ae08 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_0004af60();

/* Deleting destructor of the state holder: releases the menu (FUN_0004af60), then frees the object when flags is positive. */
SelectionState *FUN_0004ae08(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_0004af60(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
