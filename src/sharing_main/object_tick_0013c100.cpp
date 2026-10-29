/* HSTMATCH module=hstp_trans_main.prx start=0x0013c100 end=0x0013c2b0 symbol=FUN_0013c100 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/object_tick_00130b48.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/timed_obj.h"

struct GameRef { char pad[0x3c]; int mode; };
extern GameRef *DAT_003e19f0;
extern TimedObj *DAT_003e95c4;
extern char DAT_003e4915;
extern char DAT_003e4916;
enum { GAME_MODE_ACTIVE = 7, EFFECT_SIZE = 0x20, ROW_SIZE = 0x58 };
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00064c8c(float, void *);
extern "C" void FUN_00064d78(float, void *);
extern "C" void FUN_00064d08(void *, int, TimedObj *);

/* Per-frame update: advances the counters, flags the object when a table row has state 1 or 2,
   creates the effect object while an unexpired limit runs in game mode 7, and releases it when the global
   timed object has expired. */
extern "C" void FUN_0013c100(TimedObj *self)
{
  if (self->unk120 >= 0) {
    self->unk120 = self->unk120 + 1;
  }
  if (self->mode == 1 && self->sub != 0) {
    int off = self->sub->unk58 * ROW_SIZE;
    if ((&DAT_003e4915)[off] == 1 || (&DAT_003e4916)[off] == 1 || (&DAT_003e4915)[off] == 2 || (&DAT_003e4916)[off] == 2) {
      self->unk134 = 1;
    }
  }
  if (DAT_003e19f0->mode == GAME_MODE_ACTIVE) {
    if (self->effect == 0) {
      int ok = 1;
      if (self->limit >= 0 && self->elapsed < self->limit) {
        ok = 0;
      }
      if (!ok) {
        void *p = FUN_00000bcc(EFFECT_SIZE);
        if (p) p = FUN_00064c8c(-1.0f, p);
        self->effect = (TimedEffect *)p;
        FUN_00064d78(3000.0f, p);
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
    int expired = DAT_003e95c4->limit < 0;
    if (!expired) expired = DAT_003e95c4->limit <= DAT_003e95c4->elapsed;
    if (expired && effect != 0) {
      FUN_00064d08(effect, 1, DAT_003e95c4);
      self->effect = 0;
    }
  }
}
