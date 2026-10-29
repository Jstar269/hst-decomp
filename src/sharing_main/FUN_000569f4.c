/* HSTMATCH module=hstp_trans_main.prx start=0x000569f4 end=0x00056a44 symbol=FUN_000569f4 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_00056cb4();

/* Deleting destructor of the state holder: releases the menu (FUN_00056cb4), then frees the object when flags is positive. */
SelectionState *FUN_000569f4(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_00056cb4(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
