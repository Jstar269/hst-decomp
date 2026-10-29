/* HSTMATCH module=hstp_trans_main.prx start=0x00229fe0 end=0x0022a030 symbol=FUN_00229fe0 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_0022a074();

/* Deleting destructor of the state holder: releases the menu (FUN_0022a074), then frees the object when flags is positive. */
SelectionState *FUN_00229fe0(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_0022a074(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
