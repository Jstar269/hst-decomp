/* HSTMATCH module=hstp_trans_main.prx start=0x000e40ac end=0x000e415c symbol=FUN_000e40ac lang=c++ */
/* Clone of src/eboot/FUN_000dfec0.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/two_sub_obj.h"

extern "C" {
extern u8 DAT_003b09a0;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
}
/* The two sub-objects have distinct classes, each with a virtual destructor. */
struct SubAObj { virtual ~SubAObj(); };
struct SubBObj { virtual ~SubBObj(); };

/* Deleting destructor: deletes both sub-objects, runs the base destructor, frees the object when flags is positive. */
extern "C" TwoSubObj * FUN_000e40ac(TwoSubObj *self,short flags)
{
  if (self != (TwoSubObj *)0x0) {
    self->vtable = &DAT_003b09a0;
    if (self->subA != 0) {
      delete ((SubAObj *)(self->subA));
      self->subA = 0;
    }
    if (self->subB != 0) {
      delete ((SubBObj *)(self->subB));
      self->subB = 0;
    }
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
