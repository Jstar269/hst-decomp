/* HSTMATCH module=hstp_trans_main.prx start=0x0013be24 end=0x0013bf24 symbol=FUN_0013be24 lang=c++ */
/* Clone of src/eboot/FUN_0013086c.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/timed_obj.h"

extern "C" {
extern u8 DAT_003b14bc;
extern u32 DAT_003e95c4;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern int * FUN_00064d08(...);
extern void FUN_0013bf24(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

/* Destructor: clears the global timed-object pointer, runs the base teardown, deletes the three
   owned helpers and the effect, then frees the object when flag > 0. */
extern "C" TimedObj * FUN_0013be24(TimedObj *self,short flag)
{
  void *owned;
  void *effect;
  
  if (self != (TimedObj *)0x0) {
    self->vtable = &DAT_003b14bc;
    DAT_003e95c4 = 0;
    FUN_0013bf24(self,0);
    owned = self->unk7c;
    if (owned != (void *)0x0) {
      delete ((VC_0 *)(owned));
      self->unk7c = 0;
    }
    owned = self->sub;
    if (owned != (void *)0x0) {
      delete ((VC_1 *)(owned));
      self->sub = 0;
    }
    owned = self->unk84;
    if (owned != (void *)0x0) {
      delete ((VC_2 *)(owned));
      self->unk84 = 0;
    }
    effect = self->effect;
    if (effect != (void *)0x0) {
      FUN_00064d08(effect,1);
      self->effect = 0;
    }
    FUN_0001ed28(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
