/* HSTMATCH module=EBOOT.BIN start=0x0012ddd0 end=0x0012de6c symbol=FUN_0012ddd0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stage_obj.h"

extern "C" {
extern u8 DAT_00308194;
extern StageObj * DAT_0033b580;  /* the live instance */
extern void FUN_00000a00(...);
extern int * FUN_00064a08(...);
extern u32 * FUN_0028686c(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Destructor: delete the owned object, forget the live instance, destroy the sub-container and the base;
   free the object itself when deleteFlag is positive. */
extern "C" StageObj * FUN_0012ddd0(StageObj *self,short deleteFlag)
{
  VC_0 *owned;
  
  if (self != (StageObj *)0x0) {
    self->vtbl = &DAT_00308194;
    owned = (VC_0 *)self->owned;
    if (owned != (VC_0 *)0x0) {
      delete owned;
      self->owned = 0;
    }
    DAT_0033b580 = 0;
    FUN_00064a08(self->sub,0xffffffff);
    FUN_0028686c(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
