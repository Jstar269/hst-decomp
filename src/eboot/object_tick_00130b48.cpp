/* HSTMATCH module=EBOOT.BIN start=0x00130b48 end=0x00130cf8 symbol=FUN_00130b48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: FUN_00063e44 takes the game pointer as a third argument that Ghidra drops (retail leaves it in a2, which also gives the pointer its a2 colour); names and types await human review. */
#include "hst/timed_obj.h"

struct GameRef { char pad[0x3c]; int mode; };
extern GameRef *DAT_003386b0;
extern TimedObj *DAT_00340284;
extern char DAT_0033b5d5;
extern char DAT_0033b5d6;
enum { GAME_MODE_ACTIVE = 7, EFFECT_SIZE = 0x20, ROW_SIZE = 0x58 };
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00063dc8(float, void *);
extern "C" void FUN_00063eb4(float, void *);
extern "C" void FUN_00063e44(void *, int, TimedObj *);

/* Per-frame update: advances the counters, flags the object when a table row has state 1 or 2,
   creates the effect object while an unexpired limit runs in game mode 7, and releases it when the global
   timed object has expired. */
extern "C" void FUN_00130b48(TimedObj *self)
{
  if (self->unk120 >= 0) {
    self->unk120 = self->unk120 + 1;
  }
  if (self->mode == 1 && self->sub != 0) {
    int off = self->sub->unk58 * ROW_SIZE;
    if ((&DAT_0033b5d5)[off] == 1 || (&DAT_0033b5d6)[off] == 1 || (&DAT_0033b5d5)[off] == 2 || (&DAT_0033b5d6)[off] == 2) {
      self->unk134 = 1;
    }
  }
  if (DAT_003386b0->mode == GAME_MODE_ACTIVE) {
    if (self->effect == 0) {
      int ok = 1;
      if (self->limit >= 0 && self->elapsed < self->limit) {
        ok = 0;
      }
      if (!ok) {
        void *p = FUN_00000bcc(EFFECT_SIZE);
        if (p) p = FUN_00063dc8(-1.0f, p);
        self->effect = (TimedEffect *)p;
        FUN_00063eb4(3000.0f, p);
        self->effect->unk4 = 3000.0f;
        self->unk4c = 1;
      }
    }
  }
  if (self->limit >= 0) {
    self->elapsed = self->elapsed + 1;
  }
  TimedEffect *effect = self->effect;
  if (effect != 0) {
    int expired = DAT_00340284->limit < 0;
    if (!expired) expired = DAT_00340284->limit <= DAT_00340284->elapsed;
    if (expired && effect != 0) {
      FUN_00063e44(effect, 1, DAT_00340284);
      self->effect = 0;
    }
  }
}
