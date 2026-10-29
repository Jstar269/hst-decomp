/* HSTMATCH module=hstp_trans_main.prx start=0x001392d0 end=0x0013936c symbol=FUN_001392d0 lang=c++ */
/* Clone of src/eboot/FUN_0012ddd0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stage_obj.h"

extern "C" {
extern u8 DAT_003b1460;
extern StageObj * DAT_003e48c0;  /* the live instance */
extern void FUN_00000a00(...);
extern int * FUN_000658cc(...);
extern u32 * FUN_00297f98(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Destructor: delete the owned object, forget the live instance, destroy the sub-container and the base;
   free the object itself when deleteFlag is positive. */
extern "C" StageObj * FUN_001392d0(StageObj *self,short deleteFlag)
{
  VC_0 *owned;
  
  if (self != (StageObj *)0x0) {
    self->vtbl = &DAT_003b1460;
    owned = (VC_0 *)self->owned;
    if (owned != (VC_0 *)0x0) {
      delete owned;
      self->owned = 0;
    }
    DAT_003e48c0 = 0;
    FUN_000658cc(self->sub,0xffffffff);
    FUN_00297f98(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
