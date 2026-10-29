/* HSTMATCH module=EBOOT.BIN start=0x0026665c end=0x002666d4 symbol=FUN_0026665c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mover.h"

struct Vec4 {
  float f[4];
  Vec4() {}
  Vec4(const Vec4& other) {
    f[0] = other.f[0];
    f[1] = other.f[1];
    f[2] = other.f[2];
    f[3] = other.f[3];
  }
} __attribute__((aligned(16)));

extern "C" void FUN_00022434(Vec4 *out, void *param_1, void *param_2);
extern "C" void FUN_00266a24(void *param_1, Vec4 param_2, int param_3);
extern "C" void FUN_00266b1c(void *param_1);

static inline Vec4 MakeVec4(void *param_1, void *param_2)
{
  Vec4 result;
  FUN_00022434(&result, param_1, param_2);
  return result;
}

/* Steps the heading from the latched vector difference (when enabled), updates the body and remembers the heading. */
extern "C" void FUN_0026665c(Mover *self)
{
  if (self->unk160 != 0)
    FUN_00266a24(self, MakeVec4(self->unk150, self->unk130), 0);
  FUN_00266b1c(self);
  self->prevHeading = self->heading;
}
