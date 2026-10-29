/* HSTMATCH module=hstp_trans_main.prx start=0x002bf968 end=0x002bfa2c symbol=FUN_002bf968 lang=c++ */
/* Clone of src/eboot/FUN_002aff18.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_array_obj.h"

extern "C" {
extern u8 DAT_003b3264;
extern u8 DAT_003b3280;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern u32 * FUN_001087a8(...);
extern int FUN_0022667c(...);
extern void FUN_002bf8fc(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: delete the owned object, destroy the sub-object, slot vectors and bases;
   free the object itself when deleteFlag is positive. */
extern "C" SlotArrayObj * FUN_002bf968(SlotArrayObj *self,short deleteFlag)
{
  VC_0 *owned;
  
  if (self != (SlotArrayObj *)0x0) {
    self->vtbl = &DAT_003b3264;
    self->vtbl2 = &DAT_003b3280;
    owned = (VC_0 *)self->owned;
    if (owned != (VC_0 *)0x0) {
      delete owned;
      self->owned = 0;
    }
    FUN_0022667c(self->member41c,0xffffffff);
    FUN_00000788(self->slots,FUN_002bf8fc,sizeof(SlotVec),SLOT_ARRAY_COUNT);
    FUN_001087a8(&self->vtbl2,0);
    FUN_0001ed28(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
