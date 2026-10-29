/* HSTMATCH module=hstp_trans_main.prx start=0x00196bb4 end=0x00196c40 symbol=FUN_00196bb4 lang=c99 */
/* Clone of src/eboot/FUN_0018a468.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/layout_list.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b23ac;
extern u8 DAT_003b23f0;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern u32 * FUN_0022651c();

/* Deleting destructor of the layout list: destroy the list member, then the base; free when flags > 0. */
LayoutList * FUN_00196bb4(LayoutList *self,short flags)
{
  if (self != (LayoutList *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b23ac);
    self->vtableD0 = (unsigned int)(&DAT_003b23f0);
    FUN_0022651c(&self->vtableD0,0);
    if (self != (LayoutList *)0x0) {
      self->vtable = (unsigned int)(&DAT_003b0a68);
      FUN_0010642c(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
