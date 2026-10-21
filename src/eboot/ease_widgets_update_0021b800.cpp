/* HSTMATCH module=EBOOT.BIN start=0x0021b800 end=0x0021badc symbol=FUN_0021b800 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Per-frame update of the three widget slots: eases their colour/alpha channels toward targets (different targets once the counter reaches 100), writes the wobbled values to all three slots, refreshes the vector at +0x120 of the target object (38,0,0,128 scaled by 0.008), then advances or holds the counter and finishes the screen when it reaches the limit. Names provisional. */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct Slot {
  char pad[0x60];
  float f60;
  float f64;
  char pad68[0x78 - 0x68];
  float f78;
};
struct Target {
  char pad[0x118];
  int f118;
  int pad11c;
  Vec4 v120;
};
struct Env {
  char pad[0x8b];
  signed char f8b;
};
struct Self {
  char pad0[0x54];
  unsigned char f54;
  char pad55[0x64 - 0x55];
  int f64;
  Slot *p[3];
  int f74;
  int f78;
  char pad7c[0x90 - 0x7c];
  Target *f90;
  char pad94[0x198 - 0x94];
  unsigned char f198;
};
extern "C" {
extern float DAT_002f015c;
extern float DAT_0034a160;
extern float DAT_0034a164;
extern float DAT_0034a170;
extern int DAT_002eff90;
extern int DAT_002eff94;
extern Env *DAT_002cfc8c;
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

extern "C" void FUN_0021b800(Self *self)
{
  if (self->f64 >= 0) {
    Slot *p0 = self->p[0];
    float e = p0->f60;
    float c = p0->f64;
    float d = p0->f78;
    float a;
    float b;
    if (self->f64 < 100) {
      a = FUN_000ede98(e, 0.0f, DAT_002f015c, 0.01f);
      b = FUN_000ede98(c, 0.0f, DAT_002f015c, 0.01f);
      d = FUN_000ede98(d, 1.0f, DAT_002f015c, 0.01f);
    } else {
      a = FUN_000ede98(e, -DAT_0034a160, DAT_002f015c, 0.01f);
      b = FUN_000ede98(c, -DAT_0034a164, DAT_002f015c, 0.01f);
      d = FUN_000ede98(d, DAT_0034a170, DAT_002f015c, 0.01f);
    }
    for (int i = 0; i < 3; i++) {
      self->p[i]->f60 = FUN_0000bd2c(a);
      self->p[i]->f64 = FUN_0000bd2c(b);
      self->p[i]->f78 = d;
    }
    Target *t = self->f90;
    t->f118 = 0x80000026;
    Vec4 v;
    v.x = 38.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 128.0f;
    t->v120 = Scale(v, 0.008f);
    FUN_00103480(self);
    if (!(self->f64 < DAT_002eff90 + 20) && self->f198 != 0) {
      FUN_000ffb3c(self->f74, 0);
      FUN_000ffb3c(self->f78, 0);
      if (((int)DAT_002cfc8c->f8b << 28) >> 30 == 0) {
        FUN_001b1c44(DAT_0034179c, 3);
        self->f198 = 0;
        self->f64 = 100;
      }
    } else {
      FUN_000ffb3c(self->f74, 1);
      FUN_000ffb3c(self->f78, 1);
      self->f64 = self->f64 + 1;
    }
    if (!(self->f64 < DAT_002eff94)) {
      FUN_00103628(self, 1);
      self->f54 = 1;
      self->f64 = -1;
    }
  }
  FUN_00103128(self);
}
