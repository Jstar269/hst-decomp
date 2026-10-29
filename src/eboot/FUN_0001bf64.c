/* HSTMATCH module=EBOOT.BIN start=0x0001bf64 end=0x0001bfb4 symbol=FUN_0001bf64 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_0001c104();

/* Deleting destructor of the state holder: releases the menu (FUN_0001c104), then frees the object when flags is positive. */
SelectionState *FUN_0001bf64(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_0001c104(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
