/* HSTMATCH module=EBOOT.BIN start=0x0012c5ac end=0x0012c7b4 symbol=FUN_0012c5ac lang=c++ data=0x002daa5c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002daa5c-0x002daa90) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Matching idioms: error branch first as an early return; the flag != 0 arm before the else arm; the success branch falls out to the shared return 0 instead of returning 0 explicitly (the explicit form materialises !(idx < count) with xori); d and t are separate Vec4 locals (t declared after d) with d = t, and the length test is written len > 1e-5f. */
#include "hst/avatar_route.h"

typedef RouteVec4 Vec4;

extern "C" {
extern float DAT_002da3a0;
void FUN_00126d1c(char *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
Vec4 *FUN_00022518(Vec4 *, const Vec4 *);
Vec4 *FUN_00022498(float, Vec4 *, const Vec4 *);
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_0012c7d8(Route *); /* advances to the next route point and rebuilds the spline basis */
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

/* Moves the route position one step along the route; returns 1 when the route is finished (or empty). */
extern "C" int FUN_0012c5ac(Route *r)
{
  if (!(r->idx < r->count)) {
    FUN_00126d1c("ERROR: Avatar::Route::Next(): route data is empty.\n");
    return 1;
  }
  if (r->flag != 0) {
    r->t += r->speed * 0.01f;
    float progress = r->t;
    if (progress >= 1.0f) {
      r->t = progress - 1.0f;
      FUN_0012c7d8(r);
      if (r->idx >= r->count) {
        return 1;
      }
    }
  } else {
    float step = 0.95f * DAT_002da3a0 * r->speed;
    Vec4 d;
    Vec4 t;
    FUN_00022434(&t, &r->pts.data[r->idx], &r->pos);
    d = t;
    if (FUN_000224d8(&d, &d) < step * step) {
      r->idx = r->idx + 1;
      if (r->idx >= r->count) {
        r->pos = r->pts.data[r->count - 1];
        return 1;
      }
      if (FUN_000224d8(&d, &d) > 1e-05f) {
        FUN_00022518(&d, &d);
        d.w = 0.0f;
        FUN_00022498(step, &d, &d);
        FUN_00022418(&r->pos, &r->pos, &d);
      }
    } else {
      FUN_00022518(&d, &d);
      d.w = 0.0f;
      FUN_00022498(step, &d, &d);
      FUN_00022418(&r->pos, &r->pos, &d);
    }
  }
  return 0;
}
