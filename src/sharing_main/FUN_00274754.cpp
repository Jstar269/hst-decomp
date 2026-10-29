/* HSTMATCH module=hstp_trans_main.prx start=0x00274754 end=0x002747f8 symbol=FUN_00274754 lang=c++ */
/* Clone of src/eboot/FUN_002638d8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_obj.h"

extern "C" {
extern u8 DAT_003a6b38;
extern u8 DAT_003b2d94;
extern char DAT_003a6b3c[];
extern int FUN_00108124(...);
extern int FUN_00109304(...);
extern u32 * FUN_00268090(...);
extern int * FUN_0026ec7c(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Screen constructor: base constructor, ring member, one named model lookup, then virtual slot 7 builds the panel which is cleared here. */
extern "C" ScreenObj * FUN_00274754(ScreenObj *self)
{
  u32 layout;
  int model;
  
  FUN_00268090();
  self->vtable = &DAT_003b2d94;
  FUN_0026ec7c(&self->ring);
  layout = FUN_00109304(self,&DAT_003a6b38,0);
  model = FUN_00108124(layout,DAT_003a6b3c);
  self->unk1e44 = model;
  ((VC_0 *)(self))->m();
  self->panel->unk616 = 0;
  self->panel->unk736 = 0;
  self->panel->unk856 = 0;
  self->panel->unk617 = 0;
  self->panel->unk737 = 0;
  self->panel->unk857 = 0;
  return self;
}
