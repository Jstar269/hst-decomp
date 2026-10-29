/* HSTMATCH module=EBOOT.BIN start=0x0018a468 end=0x0018a4f4 symbol=FUN_0018a468 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/layout_list.h"

extern u8 DAT_0030779c;
extern u8 DAT_003090e0;
extern u8 DAT_00309124;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern u32 * FUN_00217474();

/* Deleting destructor of the layout list: destroy the list member, then the base; free when flags > 0. */
LayoutList * FUN_0018a468(LayoutList *self,short flags)
{
  if (self != (LayoutList *)0x0) {
    self->vtable = (unsigned int)(&DAT_003090e0);
    self->vtableD0 = (unsigned int)(&DAT_00309124);
    FUN_00217474(&self->vtableD0,0);
    if (self != (LayoutList *)0x0) {
      self->vtable = (unsigned int)(&DAT_0030779c);
      FUN_00100b24(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
