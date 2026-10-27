/* HSTMATCH module=EBOOT.BIN start=0x0020da38 end=0x0020e214 symbol=FUN_0020da38 lang=c++ */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
} __attribute__((aligned(16)));

struct Elem {
  int id;
  unsigned char flag;
  int c;
  Vec4 v;
};
struct Grid;
struct Game {
  char pad[0x88];
  Grid *grid;
};
struct Cfg {
  char pad[0x45];
  unsigned char f45;
  char pad2[0x8c - 0x46];
  int f8c;
  int f90;
};
struct Row {
  int v[3];
};
struct Obj {
  char pad[0x580];
  Vec4 v580;
  Vec4 v590;
  Vec4 v5a0;
  char pad2[0x82c - 0x5b0];
  Row rows[3];
};
struct Thing {
  char pad[0x14];
  float f14;
  float f18;
  char pad2[0x1c0 - 0x1c];
  float f1c0;
  float f1c4;
};

extern "C" {
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;
extern float DAT_002ef9d4;
extern float DAT_002ef9d8;
extern float DAT_002ef9dc;
extern float DAT_002ef9e0;
extern float DAT_002ef9e4;
extern float DAT_002ef9e8;
extern float DAT_002ef9ec;
extern float DAT_002ef9f0;
extern float DAT_002ef9f4;
extern float DAT_002ef9f8;
extern char DAT_002ef9fc[];
extern char DAT_002efa0c[];
extern float DAT_0034129c;
double pow(double, double);
Thing *FUN_00215a58(Obj *);
Thing *FUN_00215a20(Obj *);
unsigned FUN_0001342c();
int FUN_002156a0(Obj *);
int FUN_00215734(Obj *);
int FUN_000a7ee0(Obj *, Elem *, float, Grid *, int);
void FUN_00022450(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000a82b8(float, Obj *);
void FUN_00214e4c(Obj *, Vec4 *, int);
void FUN_0020b600(...);
}

static inline Vec4 Op(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022450(&r, &a, &b);
  return r;
}
static inline float Max(const float &a, const float &b) { return a > b ? a : b; }
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (!(v > hi) ? v : hi); }
static inline float Random() { return 4.656613e-10f * (float)(int)(FUN_0001342c() & 0xfffff800); }

extern "C" int FUN_0020da38(Obj *self)
{
  int result = 0;
  if (DAT_00338b44->f45 != 0) {
    int hit = 0;
    int strong = 0;
    if (DAT_00338b44->f90 == 1) {
      int index = DAT_00338b44->f8c - 1;
      Row *row = &self->rows[index];
      float total = (float)(row->v[0] + row->v[1] + row->v[2]);
      if (total > 0.0f) {
        float n = 3.0f;
        float mean = total / n;
        float sd = (float)pow((pow((float)row->v[0] - mean, 2.0) + pow((float)row->v[1] - mean, 2.0) + pow((float)row->v[2] - mean, 2.0)) / n, 0.5);
        float p = Max(DAT_002ef9d4, FUN_00215a58(self)->f1c0 + FUN_00215a20(self)->f1c0) +
                  sd * (10.0f * Max(DAT_002ef9d8, FUN_00215a58(self)->f1c4 + FUN_00215a20(self)->f1c4));
        if (index == 1) p *= 1.5f;
        p *= 0.01f;
        p = Clamp(p, DAT_002ef9dc, DAT_002ef9e0);
        if (Random() < p) {
          hit = 1;
          float v = (float)row->v[FUN_002156a0(self)];
          float m = Max(DAT_002ef9e4, FUN_00215a58(self)->f1c4 + FUN_00215a20(self)->f1c4);
          if (Random() < 1.0f - (total - mean) / (total + v * (3.0f * m))) strong = 1;
        }
      }
    } else if (DAT_00338b44->f90 >= 2) {
      float total = (float)(self->rows[2].v[0] + self->rows[2].v[1]);
      if (total > 0.0f) {
        float n = 2.0f;
        float mean = total / n;
        float sd = (float)pow((pow((float)self->rows[2].v[0] - mean, 2.0) + pow((float)self->rows[2].v[1] - mean, 2.0)) / n, 0.5);
        float p = Max(DAT_002ef9e8, FUN_00215a58(self)->f14 + FUN_00215a20(self)->f14) +
                  sd * Max(DAT_002ef9ec, FUN_00215a58(self)->f18 + FUN_00215a20(self)->f18);
        p *= 0.01f;
        p = Clamp(p, DAT_002ef9f0, DAT_002ef9f4);
        if (Random() < p) {
          hit = 1;
          float v = (float)(FUN_00215734(self) ? self->rows[2].v[0] : self->rows[2].v[1]);
          float m = Max(DAT_002ef9f8, FUN_00215a58(self)->f18 + FUN_00215a20(self)->f18);
          if (Random() < 1.0f - (total - mean) / (total + v * (2.0f * m))) strong = 1;
        }
      }
    }
    if (hit) {
      Elem e;
      if (FUN_000a7ee0(self, &e, *(float *)((char *)self + 0x588), DAT_003386b0->grid, 0) != 0) {
        Vec4 t = Op(e.v, self->v5a0);
        if (strong) {
          FUN_0020b600(DAT_002ef9fc);
          float dx = t.x - self->v580.x;
          float k = 0.8f * FUN_000a82b8(0.01f * DAT_0034129c, self);
          t.x -= k * (float)(dx < 0.0f ? -1 : 1);
        } else {
          FUN_0020b600(DAT_002efa0c);
          int s = self->v580.x - t.x < 0.0f ? -1 : 1;
          t.x = self->v580.x + 1.5f * (float)s;
          result = 1;
        }
        FUN_00214e4c(self, &t, 0);
      }
    }
  }
  return result;
}
// NEAR MISS 503/503 words, 3 differ (register only): retail loads rows[index].v[0] into t0 (lw t0,2092(v0);
// addu v1,t0,s0; mtc1 t0,$f0), ours picks a0. Ruled out: row as Row*/int*/Row&, no row local, int locals a/b,
// int sum local, sum orders (v1+v0+v2, v0+(v1+v2), sum += v2), unrolled loop sum, cfg local, bool flags/result,
// member function (this), static log stub FUN_0020b600 via helpers=, Sq inline helper, split total/mean decls.
// Solved: `p *= 0.01f` compound (value-first mul), `result = 1` AFTER the t.x store in the weak arm.
// near miss from lane wf20261026-e01-10 (unreviewed)
