/* HSTMATCH module=EBOOT.BIN start=0x00088388 end=0x00088600 symbol=FUN_00088388 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6, variant v18c) corrected by hand: merged else-branches split back into independent null-checked blocks, the array global read once into a local, the callee prototyped with a float parameter, loop counter declared before the walking pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scene.h"

extern "C" {
extern u8 DAT_00088600;
extern u8 DAT_00088660;
extern u8 DAT_000886c0;
extern u8 DAT_00088774;
extern u8 DAT_00234800;
extern u8 DAT_003071d8;
extern u32 DAT_00310fc4;
extern u32 DAT_003386b0;
extern u32 DAT_003386cc;
extern u32 DAT_00338714;
extern void *DAT_00338ab0;
extern u32 DAT_0034a6a8;
extern u32 DAT_0034a6ac;
extern u32 DAT_0034a6b0;
extern u32 DAT_0034a6b4;
extern u32 DAT_0034a6b8;
extern u32 DAT_0034a7e8;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_000429a0(...);
extern int FUN_00053718(...);
extern int FUN_0005ba00(...);
extern int * FUN_0005d818(...);
extern void FUN_0006df50(float);
extern void FUN_000c5110(...);
extern int FUN_002ade80(...);
extern void FUN_000887d4(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Scene deleting destructor: releases the players, helper tables and sub-objects. */
extern "C" Scene * FUN_00088388(Scene *self,short flag)
{
  unsigned i;
  void *table;

  if (self != (Scene *)0x0) {
    self->vtbl = &DAT_003071d8;
    i = 0;
    do {
      Obj *player = self->players[i];
      if (player != (Obj *)0x0) {
        delete ((VC_0 *)(player));
        self->players[i] = 0;
      }
      i = i + 1;
    } while (i < SCENE_MAX_PLAYERS);
    FUN_0006df50(2000.0f);
    FUN_000c5110();
    if (self->fukiAnim != (Obj *)0x0) {
      FUN_0005d818(self->fukiAnim,1);
      self->fukiAnim = 0;
    }
    if (self->fuki != 0) {
      FUN_00053718(self->fuki,1);
      self->fuki = 0;
    }
    table = DAT_00338ab0;
    if (table != 0) {
      if (table != 0) {
        FUN_00000788(table,FUN_000887d4,0xc,2);
        FUN_00000a00(table);
      }
      DAT_00338ab0 = 0;
    }
    if (DAT_0034a7e8 != 0) {
      FUN_000006e8(DAT_0034a7e8,(int)&DAT_00088774);
      DAT_0034a7e8 = 0;
    }
    if (DAT_0034a6a8 != 0) {
      FUN_000006e8(DAT_0034a6a8,(int)&DAT_00234800);
      DAT_0034a6a8 = 0;
    }
    if (DAT_0034a6ac != 0) {
      FUN_000006e8(DAT_0034a6ac,(int)&DAT_00234800);
      DAT_0034a6ac = 0;
    }
    if (DAT_0034a6b0 != 0) {
      FUN_000006e8(DAT_0034a6b0,(int)&DAT_000886c0);
      DAT_0034a6b0 = 0;
    }
    if (DAT_0034a6b4 != 0) {
      FUN_000006e8(DAT_0034a6b4,(int)&DAT_00088660);
      DAT_0034a6b4 = 0;
    }
    if (DAT_0034a6b8 != 0) {
      FUN_000006e8(DAT_0034a6b8,(int)&DAT_00088600);
      DAT_0034a6b8 = 0;
    }
    if (self->unka4 != 0) {
      FUN_002ade80(self->unka4,1);
      self->unka4 = 0;
    }
    if (DAT_00338714 != 0) {
      FUN_0005ba00(DAT_00338714,1);
      DAT_00338714 = 0;
    }
    if (DAT_003386cc != 0) {
      FUN_0005ba00(DAT_003386cc,1);
      DAT_003386cc = 0;
    }
    FUN_000429a0(DAT_00310fc4);
    DAT_003386b0 = 0;
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
