/* HSTMATCH module=EBOOT.BIN start=0x002289a4 end=0x00228be4 symbol=FUN_002289a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/court_prop.h"

/* Linear congruential generator constants (the rand() recurrence) and the degree-to-radian factor. */
#define RNG_MUL 0x343fd
#define RNG_ADD 0x269ec3
#define RNG_MASK 0x7fff
#define ANGLE_RANGE 0x28 /* random angles are 0..39 degrees */
#define DEG_TO_RAD 0.017453292f

typedef Float4 Vec4;

extern "C" {
void FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_00022498(float, Vec4 *, const Vec4 *);
double FUN_00020f5c(float);
double FUN_0002166c(double, double);
float FUN_000223a0(double);
void FUN_0004d280(float, void *, void *);
void FUN_0004d328(float, void *, void *);
void FUN_00055044(void *, void *);
struct Rng {
  char pad[0x1360];
  int seed;
};
extern Rng *DAT_003402a0;
}

/* s * v (out-of-line vector helper wrapped to return by value). */
static inline Vec4 Scale(float s, const Vec4 &v)
{
  Vec4 r;
  FUN_00022498(s, &r, &v);
  return r;
}

static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022418(&r, &a, &b);
  return r;
}

static inline void ScaleTo(Vec4 &dst, float s, const Vec4 &v)
{
  dst = Scale(s, v);
}

/* One step: advance the position by the scaled velocity, apply two random-angle transforms (FUN_0004d280,
   FUN_0004d328) to the matrix, and when pos.y rises above 0 count a bounce, halve the velocity, flip its y and
   switch to state 4 once there have been two bounces. */
extern "C" void FUN_002289a4(CourtProp *self)
{
  self->vel.y = (float)FUN_000223a0(FUN_0002166c(0.5553333333333333, FUN_00020f5c(self->vel.y)));
  self->pos = Add(self->pos, Scale(0.0566666685f, self->vel));
  int seed = DAT_003402a0->seed * RNG_MUL + RNG_ADD;
  DAT_003402a0->seed = seed;
  int angle = ((seed >> 16) & RNG_MASK) % ANGLE_RANGE;
  FUN_0004d280((float)angle * DEG_TO_RAD, &self->mat, &self->mat);
  seed = DAT_003402a0->seed * RNG_MUL + RNG_ADD;
  DAT_003402a0->seed = seed;
  angle = ((seed >> 16) & RNG_MASK) % ANGLE_RANGE;
  FUN_0004d328((float)angle * DEG_TO_RAD, &self->mat, &self->mat);
  if (self->pos.y > 0.0f) {
    self->bounces = self->bounces + 1;
    ScaleTo(self->vel, 0.5f, self->vel);
    self->vel.y = -self->vel.y;
    self->pos.y = -0.0f;
    if (self->bounces >= 2 && self->state != 4) {
      self->state = 4;
      self->unk434 = 1;
    }
  }
  self->unk90.x = self->pos.x;
  self->unk90.y = self->pos.y;
  self->unk90.z = self->pos.z;
  self->unk90.w = self->pos.w;
  FUN_00055044(self->unkb0, self->mat);
}
