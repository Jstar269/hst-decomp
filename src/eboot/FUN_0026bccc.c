/* HSTMATCH module=EBOOT.BIN start=0x0026bccc end=0x0026bd38 symbol=FUN_0026bccc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

extern u8 DAT_00309380;
extern u8 DAT_00309b74;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor of the sharing pane: resets the vtable to the base pane's, runs the base destructor; frees the object when delete_flag > 0. */
SharingPane * FUN_0026bccc(SharingPane *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_00309b74;
    if (self != 0) {
      self->vtable = &DAT_00309380;
      FUN_00102ea4(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
