/* HSTMATCH module=hstp_trans_main.prx start=0x0021cde8 end=0x0021d0e4 symbol=FUN_0021cde8 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/random_target_check_0020e214.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Picks a randomised scale (two clamped max terms, a random fraction, then a clamp) to turn an index into a grid record, builds two offset vectors through inline wrappers of the out-of-line vector helpers (Sub/Scale/Add/Op, each wrapper local copied once into its result object) and returns whether the final distance test is within the limit. Matching idioms: Vec4 has a user default constructor, Sub result is a named local, q is copied componentwise, ternary Max/Clamp helpers on const references reload their globals, the bool result is materialised and tested with !cc. Names provisional. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
} __attribute__((aligned(16)));

struct Rec {
  char pad0[0x10];
  Vec4 v10;
};
struct RecVec {
  Rec *data;
  unsigned size;
};
struct Grid {
  char pad[0x268];
  int base;
  RecVec recs;
};
struct Game {
  char pad[0x88];
  Grid *grid;
};
struct Obj {
  char pad[0x580];
  Vec4 v580;
  Vec4 v590;
  Vec4 v5a0;
};
struct Thing {
  char pad[0x9c];
  float f9c;
  float fa0;
};

extern "C" {
extern Game *DAT_003e19f0;
extern int DAT_0037a6c4;
extern float DAT_00397c08;
extern float DAT_00397c0c;
extern float DAT_00397c10;
extern float DAT_00397c14;
extern int DAT_003ea5c4;
Thing *FUN_0022492c(Obj *);
Thing *FUN_002248ac(Obj *);
unsigned FUN_0001342c();
void FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_000224c0(Vec4 *out, const Vec4 *a, float s);
void FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022478(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000a9cb0(Obj *, const Vec4 *, const Vec4 *, int);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}
static inline Vec4 Scale(float s, const Vec4 &v)
{
  Vec4 r;
  FUN_000224c0(&r, &v, s);
  return r;
}
static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022440(&r, &a, &b);
  return r;
}
static inline Vec4 Op(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022478(&r, &a, &b);
  return r;
}
template <class T> inline const T &Min(const T &a, const T &b) { return a < b ? a : b; }
static inline float Max(const float &a, const float &b) { return a > b ? a : b; }
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

extern "C" bool FUN_0021cde8(Obj *self)
{
  Grid *g = DAT_003e19f0->grid;
  int t = g->base;
  t += DAT_0037a6c4 + 2;
  RecVec *rv = &g->recs;
  float a = FUN_0022492c(self)->fa0;
  a = a + FUN_002248ac(self)->fa0;
  float hi = 0.01f * Max(DAT_00397c0c, a);
  float b = FUN_0022492c(self)->f9c;
  b = b + FUN_002248ac(self)->f9c;
  float lo = 0.01f * Max(DAT_00397c08, b);
  float r = lo + 4.656613e-10f * (hi - lo) * (float)(int)(FUN_0001342c() & 0xfffff800);
  float c = Clamp(r, DAT_00397c10, DAT_00397c14);
  float ft = (float)t;
  t = (int)(ft / c);
  int lim = rv->size - 1;
  t = Min(t, lim);
  Vec4 d = Sub(self->v580, self->v590);
  Vec4 p = Add(self->v580, Scale((float)(t - g->base), d));
  unsigned i = t;
  if (!(i < rv->size)) i = rv->size - 1;
  Rec *rec = rv->data + i;
  Vec4 q;
  q.x = rec->v10.x;
  q.y = rec->v10.y;
  q.z = rec->v10.z;
  q.w = rec->v10.w;
  Vec4 w = Op(q, self->v5a0);
  float f = FUN_000a9cb0(self, &w, &p, 0);
  int cc = DAT_003ea5c4 < (int)f;
  if (!cc) return true;
  return false;
}
