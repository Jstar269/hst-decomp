/* HSTMATCH module=EBOOT.BIN start=0x0024aaf4 end=0x0024ad34 symbol=FUN_0024aaf4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Clone of src/eboot/trajectory_step_002289a4.cpp (same body, fields at +0x30); addresses substituted; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
};

struct Ball {
  char pad0[0x3c];
  int state;             /* 0x3c */
  Vec4 pos;              /* 0x40 */
  char pad1[0xa0 - 0x50];
  char mat[0x30];        /* 0xa0 rotation, jittered each step */
  Vec4 posCopy;          /* 0xd0 copy of pos */
  char matOut[0x40];     /* 0xe0 matrix handed to the setter */
  char pad4[0x460 - 0x120];
  int bounces;           /* 0x460 */
  unsigned char stateChanged; /* 0x464 */
  char pad5[0x470 - 0x465];
  Vec4 vel;              /* 0x470 */
};

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

#define DEG_TO_RAD 0.017453292f
#define JITTER_DEGREES 0x28 /* random rotation range per axis, in degrees */

/* One step of a bouncing motion: updates the velocity and position, applies two random rotations, bounces at ground level and switches to state 4 after two bounces. */
extern "C" void FUN_0024aaf4(Ball *self)
{
  self->vel.y = (float)FUN_000223a0(FUN_0002166c(0.5553333333333333, FUN_00020f5c(self->vel.y)));
  self->pos = Add(self->pos, Scale(0.0566666685f, self->vel));
  int u = DAT_003402a0->seed * 0x343fd + 0x269ec3;
  DAT_003402a0->seed = u;
  int r = ((u >> 16) & 0x7fff) % JITTER_DEGREES;
  FUN_0004d280((float)r * DEG_TO_RAD, &self->mat, &self->mat);
  u = DAT_003402a0->seed * 0x343fd + 0x269ec3;
  DAT_003402a0->seed = u;
  r = ((u >> 16) & 0x7fff) % JITTER_DEGREES;
  FUN_0004d328((float)r * DEG_TO_RAD, &self->mat, &self->mat);
  if (self->pos.y > 0.0f) {
    self->bounces = self->bounces + 1;
    ScaleTo(self->vel, 0.5f, self->vel);
    self->vel.y = -self->vel.y;
    self->pos.y = -0.0f;
    if (self->bounces >= 2 && self->state != 4) {
      self->state = 4;
      self->stateChanged = 1;
    }
  }
  self->posCopy.x = self->pos.x;
  self->posCopy.y = self->pos.y;
  self->posCopy.z = self->pos.z;
  self->posCopy.w = self->pos.w;
  FUN_00055044(self->matOut, self->mat);
}
