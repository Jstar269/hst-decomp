/* HSTMATCH module=EBOOT.BIN start=0x0012c5ac end=0x0012c7b4 symbol=FUN_0012c5ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: error branch first as an early return; the flag != 0 arm before the else arm; the success branch falls out to the shared return 0 instead of returning 0 explicitly (the explicit form materialises !(idx < count) with xori); d and t are separate Vec4 locals (t declared after d) with d = t, and the length test is written len > 1e-5f. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Route {
  char pad00[0x50];
  float f50;
  char pad54[0xc];
  Vec4 v60;
  Vec4 *pts;
  char pad74[8];
  unsigned count;
  unsigned idx;
  char pad84[0xc];
  float speed;
  unsigned char flag;
};

extern "C" {
extern float DAT_002da3a0;
extern char DAT_002daa5c[];
void FUN_00126d1c(char *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
Vec4 *FUN_00022518(Vec4 *, const Vec4 *);
Vec4 *FUN_00022498(float, Vec4 *, const Vec4 *);
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_0012c7d8(Route *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

extern "C" int FUN_0012c5ac(Route *r)
{
  if (!(r->idx < r->count)) {
    FUN_00126d1c(DAT_002daa5c);
    return 1;
  }
  if (r->flag != 0) {
    r->f50 += r->speed * 0.01f;
    float t = r->f50;
    if (t >= 1.0f) {
      r->f50 = t - 1.0f;
      FUN_0012c7d8(r);
      if (r->idx >= r->count) {
        return 1;
      }
    }
  } else {
    float step = 0.95f * DAT_002da3a0 * r->speed;
    Vec4 d;
    Vec4 t;
    FUN_00022434(&t, &r->pts[r->idx], &r->v60);
    d = t;
    if (FUN_000224d8(&d, &d) < step * step) {
      r->idx = r->idx + 1;
      if (r->idx >= r->count) {
        r->v60 = r->pts[r->count - 1];
        return 1;
      }
      if (FUN_000224d8(&d, &d) > 1e-05f) {
        FUN_00022518(&d, &d);
        d.w = 0.0f;
        FUN_00022498(step, &d, &d);
        FUN_00022418(&r->v60, &r->v60, &d);
      }
    } else {
      FUN_00022518(&d, &d);
      d.w = 0.0f;
      FUN_00022498(step, &d, &d);
      FUN_00022418(&r->v60, &r->v60, &d);
    }
  }
  return 0;
}
