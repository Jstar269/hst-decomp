/* HSTMATCH module=hstp_trans_main.prx start=0x002a30f8 end=0x002a3198 symbol=FUN_002a30f8 lang=c++ */
/* Clone of src/eboot/FUN_00291aec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/material_set.h"

extern "C" {
extern u8 DAT_003b30c4;
extern void FUN_00000a00(...);
extern int FUN_0005c688(...);
extern void FUN_002a32e8(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Destructor: deletes the owned helpers, then frees the object when flag > 0. */
extern "C" MaterialSet * FUN_002a30f8(MaterialSet *self,short flag)
{
  void *owned;
  int res;
  
  if (self != (MaterialSet *)0x0) {
    self->vtable = &DAT_003b30c4;
    owned = self->owned;
    if (owned != (void *)0x0) {
      delete ((VC_0 *)(owned));
      self->owned = 0;
    }
    res = (int)self->res;
    if (res != 0) {
      FUN_0005c688(res,1);
      self->res = 0;
    }
    FUN_002a32e8(self);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
