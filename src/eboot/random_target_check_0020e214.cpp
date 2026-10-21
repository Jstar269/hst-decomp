/* HSTMATCH module=EBOOT.BIN start=0x0020e214 end=0x0020e510 symbol=FUN_0020e214 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern Game *DAT_003386b0;
extern int DAT_002d4360;
extern float DAT_002efa1c;
extern float DAT_002efa20;
extern float DAT_002efa24;
extern float DAT_002efa28;
extern int DAT_00341284;
Thing *FUN_00215a58(Obj *);
Thing *FUN_00215a20(Obj *);
unsigned FUN_0001342c();
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022498(Vec4 *out, const Vec4 *a, float s);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022450(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000a72e8(Obj *, const Vec4 *, const Vec4 *, int);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}
static inline Vec4 Scale(float s, const Vec4 &v)
{
  Vec4 r;
  FUN_00022498(&r, &v, s);
  return r;
}
static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022418(&r, &a, &b);
  return r;
}
static inline Vec4 Op(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022450(&r, &a, &b);
  return r;
}
template <class T> inline const T &Min(const T &a, const T &b) { return a < b ? a : b; }
static inline float Max(const float &a, const float &b) { return a > b ? a : b; }
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

extern "C" bool FUN_0020e214(Obj *self)
{
  Grid *g = DAT_003386b0->grid;
  int t = g->base;
  t += DAT_002d4360 + 2;
  RecVec *rv = &g->recs;
  float a = FUN_00215a58(self)->fa0;
  a = a + FUN_00215a20(self)->fa0;
  float hi = 0.01f * Max(DAT_002efa20, a);
  float b = FUN_00215a58(self)->f9c;
  b = b + FUN_00215a20(self)->f9c;
  float lo = 0.01f * Max(DAT_002efa1c, b);
  float r = lo + 4.656613e-10f * (hi - lo) * (float)(int)(FUN_0001342c() & 0xfffff800);
  float c = Clamp(r, DAT_002efa24, DAT_002efa28);
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
  float f = FUN_000a72e8(self, &w, &p, 0);
  int cc = DAT_00341284 < (int)f;
  if (!cc) return true;
  return false;
}
