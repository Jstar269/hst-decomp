/* HSTMATCH module=EBOOT.BIN start=0x00063554 end=0x0006367c symbol=FUN_00063554 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Blends two vectors of the object: out = from + (to - from) * s with s = 1 - num/den, where den is
   max(DAT_002d11bc, duration) and num is max(remaining, DAT_002d11b8); the three out-of-line vector helpers
   (0x22434 subtract, 0x22498 scale, 0x22418 add) write into plain stack temporaries that are copied
   field by field. Matching idiom: Max() returns a const reference, which gives retail's address
   select between the object member and the global. */
#include "hst/ramp_obj.h"

typedef RampVec4 V4;

extern "C" {
extern float DAT_002d11b8;
extern float DAT_002d11bc;
void FUN_00022434(V4 *, V4 *, V4 *);
void FUN_00022498(float, V4 *, V4 *);
void FUN_00022418(V4 *, V4 *, V4 *);
}

static inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }

/* Writes the blend of the ramp's two values at its current progress to `out`. */
extern "C" void FUN_00063554(V4 *out, RampObj *ramp)
{
    const float &den = Max(DAT_002d11bc, ramp->duration);
    const float &num = Max(ramp->remaining, DAT_002d11b8);
    float progress = 1.0f - num / den;
    V4 scaled;
    V4 diff;
    V4 tmpDiff;
    V4 tmpScaled;
    V4 sum;
    FUN_00022434(&tmpDiff, &ramp->to, &ramp->from);
    diff = tmpDiff;
    FUN_00022498(progress, &tmpScaled, &diff);
    scaled = tmpScaled;
    FUN_00022418(&sum, &ramp->from, &scaled);
    out->x = sum.x;
    out->y = sum.y;
    out->z = sum.z;
    out->w = sum.w;
}
