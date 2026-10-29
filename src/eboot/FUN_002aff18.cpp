/* HSTMATCH module=EBOOT.BIN start=0x002aff18 end=0x002affdc symbol=FUN_002aff18 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_array_obj.h"

extern "C" {
extern u8 DAT_00309f98;
extern u8 DAT_00309fb4;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern u32 * FUN_00102ea4(...);
extern int FUN_002175d4(...);
extern void FUN_002afeac(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: delete the owned object, destroy the sub-object, slot vectors and bases;
   free the object itself when deleteFlag is positive. */
extern "C" SlotArrayObj * FUN_002aff18(SlotArrayObj *self,short deleteFlag)
{
  VC_0 *owned;
  
  if (self != (SlotArrayObj *)0x0) {
    self->vtbl = &DAT_00309f98;
    self->vtbl2 = &DAT_00309fb4;
    owned = (VC_0 *)self->owned;
    if (owned != (VC_0 *)0x0) {
      delete owned;
      self->owned = 0;
    }
    FUN_002175d4(self->member41c,0xffffffff);
    FUN_00000788(self->slots,FUN_002afeac,sizeof(SlotVec),SLOT_ARRAY_COUNT);
    FUN_00102ea4(&self->vtbl2,0);
    FUN_0001f0f0(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
