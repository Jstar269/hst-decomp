/* HSTMATCH module=EBOOT.BIN start=0x00291aec end=0x00291b8c symbol=FUN_00291aec lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/material_set.h"

extern "C" {
extern u8 DAT_00309ddc;
extern void FUN_00000a00(...);
extern int FUN_0005ba00(...);
extern void FUN_00291cdc(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Destructor: deletes the owned helpers, then frees the object when flag > 0. */
extern "C" MaterialSet * FUN_00291aec(MaterialSet *self,short flag)
{
  void *owned;
  int res;
  
  if (self != (MaterialSet *)0x0) {
    self->vtable = &DAT_00309ddc;
    owned = self->owned;
    if (owned != (void *)0x0) {
      delete ((VC_0 *)(owned));
      self->owned = 0;
    }
    res = (int)self->res;
    if (res != 0) {
      FUN_0005ba00(res,1);
      self->res = 0;
    }
    FUN_00291cdc(self);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
