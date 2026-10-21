/* HSTMATCH module=hstp_trans_main.prx start=0x00137a18 end=0x00137c20 symbol=FUN_00137a18 lang=c++ */
/* Clone of src/eboot/follow_route_step_0012c5ac.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern float DAT_00381420;
extern char DAT_00381b4c[];
void FUN_00131f8c(char *);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
Vec4 *FUN_00022540(Vec4 *, const Vec4 *);
Vec4 *FUN_000224c0(float, Vec4 *, const Vec4 *);
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_00137c44(Route *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

extern "C" int FUN_00137a18(Route *r)
{
  if (!(r->idx < r->count)) {
    FUN_00131f8c(DAT_00381b4c);
    return 1;
  }
  if (r->flag != 0) {
    r->f50 += r->speed * 0.01f;
    float t = r->f50;
    if (t >= 1.0f) {
      r->f50 = t - 1.0f;
      FUN_00137c44(r);
      if (r->idx >= r->count) {
        return 1;
      }
    }
  } else {
    float step = 0.95f * DAT_00381420 * r->speed;
    Vec4 d;
    Vec4 t;
    FUN_0002245c(&t, &r->pts[r->idx], &r->v60);
    d = t;
    if (FUN_00022500(&d, &d) < step * step) {
      r->idx = r->idx + 1;
      if (r->idx >= r->count) {
        r->v60 = r->pts[r->count - 1];
        return 1;
      }
      if (FUN_00022500(&d, &d) > 1e-05f) {
        FUN_00022540(&d, &d);
        d.w = 0.0f;
        FUN_000224c0(step, &d, &d);
        FUN_00022440(&r->v60, &r->v60, &d);
      }
    } else {
      FUN_00022540(&d, &d);
      d.w = 0.0f;
      FUN_000224c0(step, &d, &d);
      FUN_00022440(&r->v60, &r->v60, &d);
    }
  }
  return 0;
}
