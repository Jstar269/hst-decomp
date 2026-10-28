/* HSTMATCH module=EBOOT.BIN start=0x00088258 end=0x00088388 symbol=FUN_00088258 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00088258) corrected by hand: float and symbol arguments, pointer-typed globals, loop declaration order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scene.h"

extern u8 DAT_003071d8;
extern u32 DAT_00310fc4;
extern unsigned char DAT_003386b8;
extern int DAT_003386b0;
extern void FUN_0001f06c();
extern void FUN_0001f21c();
extern void FUN_00042698();
extern void FUN_0006df50(float);
extern char *FUN_0022a930();
extern char DAT_0030fe20;

/* Scene constructor: puts the state machine in state 11 and registers the object as the global scene. */
enum { PLAYERS_WORD = 0x1c }; /* word index of Scene.players */

Scene *FUN_00088258(Scene *self)
{
  unsigned int i;
  Obj **p;
  char *net;

  FUN_0001f06c();
  self->vtbl = &DAT_003071d8;
  self->state = 0xb;
  self->next = 0;
  self->unk44 = 0;
  self->unk48 = 0;
  self->unk4c = 0;
  self->unk50 = 0;
  self->unk54 = 0;
  self->busy = 0;
  self->unk59 = 0;
  self->unk5a = 0;
  self->unk5b = 0;
  self->side = 0;
  self->unk60 = 1;
  self->unk64 = 1;
  self->unk68 = 0;
  self->timer = 0;
  self->fuki = 0;
  self->fukiAnim = 0;
  self->ball = 0;
  self->unk8c = 0;
  self->effect = 0;
  self->inpane = 0;
  self->banner = 0;
  self->unk9c = 0;
  self->score = 0;
  self->unka4 = 0;
  DAT_003386b0 = (int)self;
  FUN_00042698(DAT_00310fc4, 0x100, 0x80);
  FUN_0006df50(2060.0f);
  FUN_0001f21c(&DAT_0030fe20, self);
  i = 0;
  p = (Obj **)self; /* walk the players array from the object base */
  do {
    i++;
    p[PLAYERS_WORD] = 0;
    p++;
  } while (i < SCENE_MAX_PLAYERS);
  if (DAT_003386b8 != 0) {
    net = FUN_0022a930();
    net[0xab4f] = 0;
    net = FUN_0022a930();
    net[0xab50] = 0;
  }
  return self;
}
