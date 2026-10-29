/* HSTMATCH module=EBOOT.BIN start=0x00062418 end=0x00062468 symbol=FUN_00062418 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_000626bc();

/* Deleting destructor of the state holder: releases the menu (FUN_000626bc), then frees the object when flags is positive. */
SelectionState *FUN_00062418(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_000626bc(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
