/* HSTMATCH module=EBOOT.BIN start=0x002289a4 end=0x00228be4 symbol=FUN_002289a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
};

struct Self {
  char pad0[0x3c];
  int f3c;
  Vec4 pos;
  char pad1[0x60 - 0x50];
  char mat[0x30];
  Vec4 f90;
  char pad3[0xb0 - 0xa0];
  char f_b0[0x40];
  char pad4[0x430 - 0xf0];
  int f430;
  unsigned char b434;
  char pad5[0x440 - 0x435];
  Vec4 f440;
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

extern "C" void FUN_002289a4(Self *self)
{
  self->f440.y = (float)FUN_000223a0(FUN_0002166c(0.5553333333333333, FUN_00020f5c(self->f440.y)));
  self->pos = Add(self->pos, Scale(0.0566666685f, self->f440));
  int u = DAT_003402a0->seed * 0x343fd + 0x269ec3;
  DAT_003402a0->seed = u;
  int r = ((u >> 16) & 0x7fff) % 0x28;
  FUN_0004d280((float)r * 0.017453292f, &self->mat, &self->mat);
  u = DAT_003402a0->seed * 0x343fd + 0x269ec3;
  DAT_003402a0->seed = u;
  r = ((u >> 16) & 0x7fff) % 0x28;
  FUN_0004d328((float)r * 0.017453292f, &self->mat, &self->mat);
  if (self->pos.y > 0.0f) {
    self->f430 = self->f430 + 1;
    ScaleTo(self->f440, 0.5f, self->f440);
    self->f440.y = -self->f440.y;
    self->pos.y = -0.0f;
    if (self->f430 >= 2 && self->f3c != 4) {
      self->f3c = 4;
      self->b434 = 1;
    }
  }
  self->f90.x = self->pos.x;
  self->f90.y = self->pos.y;
  self->f90.z = self->pos.z;
  self->f90.w = self->pos.w;
  FUN_00055044(self->f_b0, self->mat);
}
