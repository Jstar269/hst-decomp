/* HSTMATCH module=EBOOT.BIN start=0x0012c530 end=0x0012c5ac symbol=FUN_0012c530 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128c) corrected by hand: typed Vec4/Mat4/object views instead of undefined4 locals, branch order flipped (flag-set arm first), out/poly locals declared out first, cube computed as (t*t)*t from the squared local; readability pass; exact match verified; names and types await human review. */
#include "hst/avatar_route.h"

extern RouteVec4 *FUN_00022548(RouteVec4 *out, const RouteMat4 *m, const RouteVec4 *v); /* matrix * vector */

/* Writes the route's current x and z to out: on a spline segment basis * (t^3, t^2, t, 1), otherwise the stored position. */
void FUN_0012c530(Route *route, float *out)
{
  RouteVec4 r;
  RouteVec4 v;

  if (route->flag != 0) {
    float t = route->t;
    v.z = t;
    v.y = t * t;
    v.x = v.y * t;
    v.w = 1.0f;
    FUN_00022548(&r, &route->basis, &v);
    out[0] = r.x;
    out[2] = r.z;
  }
  else {
    out[0] = route->pos.x;
    out[2] = route->pos.z;
  }
}
