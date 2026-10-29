/* HSTMATCH module=EBOOT.BIN start=0x002638d8 end=0x0026397c symbol=FUN_002638d8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_obj.h"

extern "C" {
extern u8 DAT_002fdee4;
extern u8 DAT_00309aac;
extern char DAT_002fdee8[];
extern int FUN_001026b8(...);
extern int FUN_001039d8(...);
extern u32 * FUN_00257be0(...);
extern int * FUN_0025de54(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Screen constructor: base constructor, ring member, one named model lookup, then virtual slot 7 builds the panel which is cleared here. */
extern "C" ScreenObj * FUN_002638d8(ScreenObj *self)
{
  u32 layout;
  int model;
  
  FUN_00257be0();
  self->vtable = &DAT_00309aac;
  FUN_0025de54(&self->ring);
  layout = FUN_001039d8(self,&DAT_002fdee4,0);
  model = FUN_001026b8(layout,DAT_002fdee8);
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
