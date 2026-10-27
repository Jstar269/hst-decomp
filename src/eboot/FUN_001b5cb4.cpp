/* HSTMATCH module=EBOOT.BIN start=0x001b5cb4 end=0x001b5ff0 symbol=FUN_001b5cb4 lang=c++ data=0x002e99b4 */
/* Hand-written reconstruction of FUN_001b5cb4; matching idioms: switch preload id with shared-body case group (1/12/0x22), Vec4 Scale/Sub inlines with callee param order, separate float temp for the final multiply; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e99b4-0x002e99bf) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct Sub1 {
  char pad[0x234];
  int f234;
};
struct Sub3 {
  char pad[0x4e8];
  int f4e8;
};
struct Ctx {
  char pad0[0x70];
  Sub3 *arr[6];
  Sub1 *f88;
};
struct G2 {
  char pad[0x1364];
  int f1364;
};

extern "C" {
extern G2 *DAT_003402a0;
extern Ctx *DAT_003386b0;
extern char DAT_0034179c[];
extern float DAT_002e99a0;
extern float DAT_002e99a4;
extern float DAT_002e99a8;
extern float DAT_002e99ac;
extern float DAT_002e99b0;
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_001b1d10(void *, int, int, int);
void FUN_001b210c(void *, int *, float, float);
void FUN_001b28f0(void *, char *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_00022498(&r, &v, s);
  return r;
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" int FUN_001b5cb4(int unused, int kind, int p3, const Vec4 *p4, const Vec4 *p5)
{
  int id = 0x75;
  switch (kind) {
  case 1:
  case 12:
  case 0x22:
    id = 0x54;
    break;
  case 0x2:
    id = 0x1e;
    break;
  case 0x1a:
    id = 0x1d;
    break;
  case 0x16:
    id = 0x1f;
    break;
  case 0x30:
    id = 0x23;
    break;
  case 0xd:
    id = 0x20;
    break;
  case 0xe:
    id = 0x26;
    break;
  case 0x18:
    id = 0x27;
    break;
  case 0x19:
    id = 0x25;
    break;
  case 0x15:
    id = 0x28;
    break;
  case 0x17:
    id = 0x2a;
    break;
  case 0x20:
    id = 0x21;
    break;
  case 0x1c:
    id = 0x2b;
    break;
  case 0x1d:
    id = 0x2c;
    break;
  case 0x1f:
    id = 0x2d;
    break;
  case 0x2b:
    id = 0x22;
    break;
  }
  int result = -1;
  if (id != 0x75) {
    Vec4 t;
    Vec4 d;
    t = Scale(*p5, FUN_000224d8(p4, p5));
    d = Sub(*p4, t);
    float lenD = FUN_00022e44(FUN_000224d8(&d, &d));
    float lenT = FUN_00022e44(FUN_000224d8(&t, &t));
    float s = lenT + DAT_002e99a4 * lenD; float w = s * DAT_002e99a0;
    float v = Clamp(w, DAT_002e99ac, DAT_002e99b0);
    if (v >= DAT_002e99a8) {
      result = FUN_001b1d10(DAT_0034179c, id, p3, 0);
      FUN_001b210c(DAT_0034179c, &result, v, v);
    }
  }
  if (DAT_003402a0->f1364 == 9) {
    switch (kind) {
    case 2:
    case 0x1a:
    case 0x16: {
      int idx = DAT_003386b0->f88->f234;
      if (idx >= 0) {
        Sub3 *s = DAT_003386b0->arr[idx];
        if (s != 0 && s->f4e8 == 1)
          FUN_001b28f0(DAT_0034179c, "court_beep");
      }
      break;
    }
    }
  }
  return result;
}
