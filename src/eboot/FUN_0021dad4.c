/* HSTMATCH module=EBOOT.BIN start=0x0021dad4 end=0x0021db30 symbol=FUN_0021dad4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/parts_pane.h"

extern char DAT_00309764[];
extern void FUN_00000a00(PartsPane *);
extern void FUN_00102ea4(PartsPane *, int);

/* PartsPane deleting destructor: resets the vtable, runs the base destructor, frees the pane when flag > 0. */
PartsPane * FUN_0021dad4(PartsPane *self,short flag)
{
  if (self != (PartsPane *)0x0) {
    self->base.vtbl = DAT_00309764;
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
