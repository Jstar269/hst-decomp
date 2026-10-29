/* HSTMATCH module=hstp_trans_main.prx start=0x0001badc end=0x0001bb2c symbol=FUN_0001badc lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_0001bc34();

/* Deleting destructor of the state holder: releases the menu (FUN_0001bc34), then frees the object when flags is positive. */
SelectionState *FUN_0001badc(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_0001bc34(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
