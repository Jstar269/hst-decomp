/* HSTMATCH module=EBOOT.BIN start=0x0026397c end=0x00263a40 symbol=FUN_0026397c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed the float argument and deallocation receiver; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_obj.h"

extern u8 DAT_00309aac;
extern u32 DAT_00331b84;
extern u32 DAT_003415ac;
extern void FUN_00000a00(u32 *);
extern void FUN_00063478(float,u32);
extern void FUN_00103628(u32, int);
extern u32 * FUN_00258180();
extern u32 * FUN_0025e600();

/* Screen deleting destructor: clear the panel flags, destroy the ring member and the base, free when delete_flag is positive. */
ScreenObj * FUN_0026397c(ScreenObj *self,short delete_flag)
{
  if (self != (ScreenObj *)0x0) {
    self->vtable = &DAT_00309aac;
    FUN_00063478(203000.0f,DAT_00331b84);
    FUN_00103628(DAT_003415ac,1);
    self->panel->unk616 = 0;
    self->panel->unk736 = 0;
    self->panel->unk856 = 0;
    self->panel->unk617 = 0;
    self->panel->unk737 = 0;
    self->panel->unk857 = 0;
    FUN_0025e600(&self->ring,-1);
    FUN_00258180(self,0);
    if (0 < delete_flag) {
      FUN_00000a00((u32 *)self);
    }
  }
  return self;
}
