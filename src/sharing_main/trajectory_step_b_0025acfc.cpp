/* HSTMATCH module=hstp_trans_main.prx start=0x0025acfc end=0x0025af3c symbol=FUN_0025acfc lang=c++ */
/* Clone of src/eboot/trajectory_step_b_0024aaf4.cpp (hstclone.py tag fm4c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
};

struct Ball {
  char pad0[0x3c];
  int f3c;
  Vec4 pos;
  char pad1[0xa0 - 0x50];
  char mat[0x30];
  Vec4 f_d0;
  char f_e0[0x40];
  char pad4[0x460 - 0x120];
  int f460;
  unsigned char b464;
  char pad5[0x470 - 0x465];
  Vec4 f470;
};

extern "C" {
void FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_000224c0(float, Vec4 *, const Vec4 *);
double FUN_00020f84(float);
double FUN_00021694(double, double);
float FUN_000223c8(double);
void FUN_0004d5f8(float, void *, void *);
void FUN_0004d6a0(float, void *, void *);
void FUN_00055b64(void *, void *);
struct Rng {
  char pad[0x1360];
  int seed;
};
extern Rng *DAT_003e95e0;
}

static inline Vec4 Scale(float s, const Vec4 &v)
{
  Vec4 r;
  FUN_000224c0(s, &r, &v);
  return r;
}

static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022440(&r, &a, &b);
  return r;
}

static inline void ScaleTo(Vec4 &dst, float s, const Vec4 &v)
{
  dst = Scale(s, v);
}

extern "C" void FUN_0025acfc(Ball *self)
{
  self->f470.y = (float)FUN_000223c8(FUN_00021694(0.5553333333333333, FUN_00020f84(self->f470.y)));
  self->pos = Add(self->pos, Scale(0.0566666685f, self->f470));
  int u = DAT_003e95e0->seed * 0x343fd + 0x269ec3;
  DAT_003e95e0->seed = u;
  int r = ((u >> 16) & 0x7fff) % 0x28;
  FUN_0004d5f8((float)r * 0.017453292f, &self->mat, &self->mat);
  u = DAT_003e95e0->seed * 0x343fd + 0x269ec3;
  DAT_003e95e0->seed = u;
  r = ((u >> 16) & 0x7fff) % 0x28;
  FUN_0004d6a0((float)r * 0.017453292f, &self->mat, &self->mat);
  if (self->pos.y > 0.0f) {
    self->f460 = self->f460 + 1;
    ScaleTo(self->f470, 0.5f, self->f470);
    self->f470.y = -self->f470.y;
    self->pos.y = -0.0f;
    if (self->f460 >= 2 && self->f3c != 4) {
      self->f3c = 4;
      self->b464 = 1;
    }
  }
  self->f_d0.x = self->pos.x;
  self->f_d0.y = self->pos.y;
  self->f_d0.z = self->pos.z;
  self->f_d0.w = self->pos.w;
  FUN_00055b64(self->f_e0, self->mat);
}
