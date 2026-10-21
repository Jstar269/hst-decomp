/* HSTMATCH module=hstp_trans_main.prx start=0x0022ad74 end=0x0022b050 symbol=FUN_0022ad74 lang=c++ */
/* Clone of src/eboot/ease_widgets_update_0021b800.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern float DAT_00398528;
extern float DAT_003f3490;
extern float DAT_003f3494;
extern float DAT_003f34a0;
extern int DAT_0039835c;
extern int DAT_00398360;
extern Env *DAT_003751d4;
extern char DAT_003eaad8[];
float FUN_000f3560(float, float, float, float);
float FUN_0000bd44(float);
void FUN_000224c0(Vec4 *out, const Vec4 *in, float s);
void FUN_00108dac(void *);
void FUN_00105470(int, int);
void FUN_001bfc3c(void *, int);
void FUN_00108f54(void *, int);
void FUN_00108a2c(void *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_000224c0(&r, &v, s);
  return r;
}

extern "C" void FUN_0022ad74(Self *self)
{
  if (self->f64 >= 0) {
    Slot *p0 = self->p[0];
    float e = p0->f60;
    float c = p0->f64;
    float d = p0->f78;
    float a;
    float b;
    if (self->f64 < 100) {
      a = FUN_000f3560(e, 0.0f, DAT_00398528, 0.01f);
      b = FUN_000f3560(c, 0.0f, DAT_00398528, 0.01f);
      d = FUN_000f3560(d, 1.0f, DAT_00398528, 0.01f);
    } else {
      a = FUN_000f3560(e, -DAT_003f3490, DAT_00398528, 0.01f);
      b = FUN_000f3560(c, -DAT_003f3494, DAT_00398528, 0.01f);
      d = FUN_000f3560(d, DAT_003f34a0, DAT_00398528, 0.01f);
    }
    for (int i = 0; i < 3; i++) {
      self->p[i]->f60 = FUN_0000bd44(a);
      self->p[i]->f64 = FUN_0000bd44(b);
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
    FUN_00108dac(self);
    if (!(self->f64 < DAT_0039835c + 20) && self->f198 != 0) {
      FUN_00105470(self->f74, 0);
      FUN_00105470(self->f78, 0);
      if (((int)DAT_003751d4->f8b << 28) >> 30 == 0) {
        FUN_001bfc3c(DAT_003eaad8, 3);
        self->f198 = 0;
        self->f64 = 100;
      }
    } else {
      FUN_00105470(self->f74, 1);
      FUN_00105470(self->f78, 1);
      self->f64 = self->f64 + 1;
    }
    if (!(self->f64 < DAT_00398360)) {
      FUN_00108f54(self, 1);
      self->f54 = 1;
      self->f64 = -1;
    }
  }
  FUN_00108a2c(self);
}
