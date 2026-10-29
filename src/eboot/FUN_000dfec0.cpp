/* HSTMATCH module=EBOOT.BIN start=0x000dfec0 end=0x000dff70 symbol=FUN_000dfec0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/two_sub_obj.h"

extern "C" {
extern u8 DAT_003076d4;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
}
/* The two sub-objects have distinct classes, each with a virtual destructor. */
struct SubAObj { virtual ~SubAObj(); };
struct SubBObj { virtual ~SubBObj(); };

/* Deleting destructor: deletes both sub-objects, runs the base destructor, frees the object when flags is positive. */
extern "C" TwoSubObj * FUN_000dfec0(TwoSubObj *self,short flags)
{
  if (self != (TwoSubObj *)0x0) {
    self->vtable = &DAT_003076d4;
    if (self->subA != 0) {
      delete ((SubAObj *)(self->subA));
      self->subA = 0;
    }
    if (self->subB != 0) {
      delete ((SubBObj *)(self->subB));
      self->subB = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
