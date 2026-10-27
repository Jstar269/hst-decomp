/* HSTMATCH module=hstp_trans_main.prx start=0x001c3974 end=0x001c3cb0 symbol=FUN_001c3974 lang=c++ data=0x00391570 */
/* Hand-written reconstruction (port of src/eboot/FUN_001b5cb4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00391570-0x0039157b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern G2 *DAT_003e95e0;
extern Ctx *DAT_003e19f0;
extern char DAT_003eaad8[];
extern float DAT_0039155c;
extern float DAT_00391560;
extern float DAT_00391564;
extern float DAT_00391568;
extern float DAT_0039156c;
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
Vec4 *FUN_000224c0(Vec4 *, const Vec4 *, float);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_001bfd3c(void *, int, int, int);
void FUN_001c01a0(void *, int *, float, float);
void FUN_001c0984(void *, char *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_000224c0(&r, &v, s);
  return r;
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" int FUN_001c3974(int unused, int kind, int p3, const Vec4 *p4, const Vec4 *p5)
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
    t = Scale(*p5, FUN_00022500(p4, p5));
    d = Sub(*p4, t);
    float lenD = FUN_00022e6c(FUN_00022500(&d, &d));
    float lenT = FUN_00022e6c(FUN_00022500(&t, &t));
    float s = lenT + DAT_00391560 * lenD; float w = s * DAT_0039155c;
    float v = Clamp(w, DAT_00391568, DAT_0039156c);
    if (v >= DAT_00391564) {
      result = FUN_001bfd3c(DAT_003eaad8, id, p3, 0);
      FUN_001c01a0(DAT_003eaad8, &result, v, v);
    }
  }
  if (DAT_003e95e0->f1364 == 9) {
    switch (kind) {
    case 2:
    case 0x1a:
    case 0x16: {
      int idx = DAT_003e19f0->f88->f234;
      if (idx >= 0) {
        Sub3 *s = DAT_003e19f0->arr[idx];
        if (s != 0 && s->f4e8 == 1)
          FUN_001c0984(DAT_003eaad8, "court_beep");
      }
      break;
    }
    }
  }
  return result;
}
