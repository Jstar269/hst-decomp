/* HSTMATCH module=EBOOT.BIN start=0x001ed4a8 end=0x001ed87c symbol=FUN_001ed4a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/prize_camera.h"

typedef PrizeVec4 V4;

struct M4 {
    V4 r0, r1, r2, r3;
};

/* Global context; flip selects which tilt angle is used. */
struct Ctx {
    char pad[0x521];
    unsigned char flip; /* 0x521 */
};

extern "C" {
extern M4 DAT_002bc410;
Ctx *FUN_001ee200(void);
void FUN_0004d280(M4 *, M4 *, float);
void FUN_00022518(V4 *, const V4 *);
void FUN_000224f8(V4 *, const V4 *, const V4 *);
void FUN_00022570(M4 *, M4 *, const M4 *);
void FUN_00022498(V4 *, const V4 *, float);
void FUN_00022418(V4 *, const V4 *, const V4 *);
void FUN_000609f8(PrizeCamera *);
void FUN_0006107c(PrizeCamera *, const V4 *, float);
}

inline V4 Direction(const V4 &v)
{
    V4 r;
    FUN_00022518(&r, &v);
    r.w = 0.0f;
    return r;
}

inline V4 operator*(const V4 &v, float s)
{
    V4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

inline V4 operator+(const V4 &a, const V4 &b)
{
    V4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}

/* Selects entry idx: copies its fov and clip planes, sets the target to pos raised by the entry's offset, and
   puts the eye at the entry's distance along a direction built from dir and the tilt rotation (tilt_win when
   flip is set, else tilt). */
extern "C" void FUN_001ed4a8(PrizeCamera *self, const V4 *pos, const V4 *dir, int idx)
{
    V4 p = *pos;
    V4 d = *dir;
    self->unk94 = 0;
    self->sel = idx;
    PrizeCamEntry *e = &self->ent[idx];
    self->fov_x = e->fov_x;
    self->near_plane = e->near_plane;
    self->far_plane = e->far_plane;
    p.y += e->offset_y;
    self->target = p;
    M4 rot = DAT_002bc410;
    if (FUN_001ee200()->flip)
        FUN_0004d280(&rot, &rot, e->tilt_win);
    else
        FUN_0004d280(&rot, &rot, e->tilt);
    M4 m = DAT_002bc410;
    m.r2 = d;
    FUN_00022518(&m.r1, &m.r1);
    m.r1.w = 0.0f;
    FUN_000224f8(&m.r0, &m.r1, &m.r2);
    FUN_00022518(&m.r0, &m.r0);
    m.r0.w = 0.0f;
    FUN_000224f8(&m.r2, &m.r0, &m.r1);
    m.r3 = m.r3;
    FUN_00022570(&m, &m, &rot);
    self->eye = p + Direction(m.r2) * e->distance;
    FUN_000609f8(self);
    FUN_0006107c(self, &DAT_002bc410.r1, e->default_angle_y);
    FUN_000609f8(self);
}
