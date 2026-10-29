/* HSTMATCH module=EBOOT.BIN start=0x000faea4 end=0x000faf9c symbol=FUN_000faea4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the tested global DAT_0034a820 is also the argument of FUN_00291cdc (Ghidra dropped it; retail loads it into a0), which also fixes the s0/s1 assignment; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hud_scene.h"

extern "C" {
extern u8 DAT_00307760;
extern HudScene *DAT_00338c20;
extern u32 DAT_0034a820;
extern void FUN_00000a00(...);
extern HudScene * FUN_0001f0f0(...);
extern void FUN_00291cdc(...);

}
struct HudPart { virtual ~HudPart(); };

/* Destructor: delete the three owned parts, release the global resource, run the base destructor and
   free the object when flag > 0. */
extern "C" HudScene * FUN_000faea4(HudScene *self,short flag)
{
  HudPart *part;
  
  if (self != (HudScene *)0x0) {
    self->vptr = &DAT_00307760;
    DAT_00338c20 = 0;
    part = self->unk3c;
    if (part != 0) {
      delete part;
      self->unk3c = 0;
    }
    part = self->unk44;
    if (part != 0) {
      delete part;
      self->unk44 = 0;
    }
    part = self->unk40;
    if (part != 0) {
      delete part;
      self->unk40 = 0;
    }
    if (DAT_0034a820 != 0) {
      FUN_00291cdc(DAT_0034a820);
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
