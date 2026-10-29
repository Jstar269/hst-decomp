/* HSTMATCH module=EBOOT.BIN start=0x001ffcc0 end=0x001ffdbc symbol=FUN_001ffcc0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the global tested before FUN_000009e4 is that call's argument (Ghidra dropped it, so retail loads it into a0); readability pass; exact match verified; names and types await human review. */
#include "hst/regulation_menu.h"

extern "C" {
extern void *DAT_0034a144;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(...);
extern int FUN_002175d4(Animator *,int);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: free the unit list, delete the layout, destroy the animators (last first), free when flags > 0. */
extern "C" RegulationMenu * FUN_001ffcc0(RegulationMenu *self,short flags)
{
  int *layout;
  
  if (self != 0) {
    if (DAT_0034a144) {
      FUN_000009e4(DAT_0034a144);
      DAT_0034a144 = 0;
    }
    layout = (int *)self->layout;
    if (layout != (int *)0x0) {
      delete ((VC_0 *)(layout));
      self->layout = 0;
    }
    FUN_002175d4(&self->anims[8],0xffffffff);
    FUN_002175d4(&self->anims[7],0xffffffff);
    FUN_002175d4(&self->anims[6],0xffffffff);
    FUN_002175d4(&self->anims[5],0xffffffff);
    FUN_002175d4(&self->anims[4],0xffffffff);
    FUN_002175d4(&self->anims[3],0xffffffff);
    FUN_002175d4(&self->anims[2],0xffffffff);
    FUN_002175d4(&self->anims[1],0xffffffff);
    FUN_002175d4(&self->anims[0],0xffffffff);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
