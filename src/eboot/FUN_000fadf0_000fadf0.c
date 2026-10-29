/* HSTMATCH module=EBOOT.BIN start=0x000fadf0 end=0x000faea4 symbol=FUN_000fadf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: kept each allocation result through the constructor and member-store join; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hud_scene.h"

extern u8 DAT_00307760;
extern HudScene *DAT_00338c20;
extern void *FUN_00000bcc(int size);
extern u32 * FUN_0001f06c();
extern void FUN_0001f21c();
extern void *FUN_000f78ac(void *param_1);
extern void *FUN_000fba28(void *param_1);
extern void *FUN_001fc31c(void *param_1,int param_2);

/* Construct the scene: set the vtable, register it globally and allocate its three parts. */
HudScene * FUN_000fadf0(HudScene *self)
{
  void *p;
  
  FUN_0001f06c();
  self->vptr = &DAT_00307760;
  self->unk3c = 0;
  self->countdown = 0;
  DAT_00338c20 = self;
  p = FUN_00000bcc(0x158);
  if (p != 0) p = FUN_000f78ac(p);
  self->unk3c = p;
  p = FUN_00000bcc(0x60);
  if (p != 0) p = FUN_000fba28(p);
  self->unk44 = p;
  p = FUN_00000bcc(0x58);
  if (p != 0) p = FUN_001fc31c(p,0);
  self->unk40 = p;
  FUN_0001f21c(self,p);
  FUN_0001f21c(self,self->unk44);
  return self;
}
