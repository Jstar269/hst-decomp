/* HSTMATCH module=hstp_trans_main.prx start=0x00063304 end=0x00063354 symbol=FUN_00063304 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_00000a00();
extern void FUN_00063544();

/* Deleting destructor of the state holder: releases the menu (FUN_00063544), then frees the object when flags is positive. */
SelectionState *FUN_00063304(SelectionState *self,short flags)
{
  if ((self != 0) && (FUN_00063544(), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
