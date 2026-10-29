/* HSTMATCH module=EBOOT.BIN start=0x0021b800 end=0x0021badc symbol=FUN_0021b800 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Per-frame update of the three widget slots: eases their colour/alpha channels toward targets (different targets once the counter reaches 100), writes the wobbled values to all three slots, refreshes the vector at +0x120 of the target object (38,0,0,128 scaled by 0.008), then advances or holds the counter and finishes the screen when it reaches the limit. Names provisional. */
#include "hst/ease_screen.h"

struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct EaseTarget {
  char pad[0x118];
  int unk118;
  int pad11c;
  Vec4 v120;
};
struct PadState {
  char pad[0x8b];
  signed char unk8b;
};
enum { COUNTER_PHASE_TWO = 100 };  /* counter value where the targets switch */

extern "C" {
extern float DAT_002f015c;
extern float DAT_0034a160;
extern float DAT_0034a164;
extern float DAT_0034a170;
extern int DAT_002eff90;
extern int DAT_002eff94;
extern PadState *DAT_002cfc8c;
extern char DAT_0034179c[];
float FUN_000ede98(float, float, float, float);
float FUN_0000bd2c(float);
void FUN_00022498(Vec4 *out, const Vec4 *in, float s);
void FUN_00103480(void *);
void FUN_000ffb3c(int, int);
void FUN_001b1c44(void *, int);
void FUN_00103628(void *, int);
void FUN_00103128(void *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_00022498(&r, &v, s);
  return r;
}

extern "C" void FUN_0021b800(EaseScreen *self)
{
  if (self->counter >= 0) {
    EaseSlot *first = self->slots[0];
    float old60 = first->unk60;
    float old64 = first->unk64;
    float level = first->unk78;
    float new60;
    float new64;
    if (self->counter < COUNTER_PHASE_TWO) {
      new60 = FUN_000ede98(old60, 0.0f, DAT_002f015c, 0.01f);
      new64 = FUN_000ede98(old64, 0.0f, DAT_002f015c, 0.01f);
      level = FUN_000ede98(level, 1.0f, DAT_002f015c, 0.01f);
    } else {
      new60 = FUN_000ede98(old60, -DAT_0034a160, DAT_002f015c, 0.01f);
      new64 = FUN_000ede98(old64, -DAT_0034a164, DAT_002f015c, 0.01f);
      level = FUN_000ede98(level, DAT_0034a170, DAT_002f015c, 0.01f);
    }
    for (int i = 0; i < EASE_SLOT_COUNT; i++) {
      self->slots[i]->unk60 = FUN_0000bd2c(new60);
      self->slots[i]->unk64 = FUN_0000bd2c(new64);
      self->slots[i]->unk78 = level;
    }
    EaseTarget *target = self->target;
    target->unk118 = 0x80000026;
    Vec4 offset;
    offset.x = 38.0f;
    offset.y = 0.0f;
    offset.z = 0.0f;
    offset.w = 128.0f;
    target->v120 = Scale(offset, 0.008f);
    FUN_00103480(self);
    if (!(self->counter < DAT_002eff90 + 20) && self->unk198 != 0) {
      FUN_000ffb3c(self->objects[0], 0);
      FUN_000ffb3c(self->objects[1], 0);
      if (((int)DAT_002cfc8c->unk8b << 28) >> 30 == 0) {
        FUN_001b1c44(DAT_0034179c, 3);
        self->unk198 = 0;
        self->counter = COUNTER_PHASE_TWO;
      }
    } else {
      FUN_000ffb3c(self->objects[0], 1);
      FUN_000ffb3c(self->objects[1], 1);
      self->counter = self->counter + 1;
    }
    if (!(self->counter < DAT_002eff94)) {
      FUN_00103628(self, 1);
      self->finished = 1;
      self->counter = EASE_COUNTER_IDLE;
    }
  }
  FUN_00103128(self);
}
