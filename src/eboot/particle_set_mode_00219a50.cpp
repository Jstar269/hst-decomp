/* HSTMATCH module=EBOOT.BIN start=0x00219a50 end=0x00219fa0 symbol=FUN_00219a50 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/particle_set_mode_00228f68.cpp); Init/Step are static inline helpers expanded in place (Step's respawn calls the out-of-line copy of Init, FUN_002198b4, directly: MWCC does not inline a call made from an inlined body); exact match verified; names and types await human review. */
#include "hst/particle_sys.h"

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

struct Particle {           /* PARTICLE_SIZE bytes */
    char pad0[0x10];
    Mat4 m;                 /* +0x10 */
    char pad50[0x20];
    float spin;             /* +0x70 */
    char pad74[0xc];
    Vec4 vel;               /* +0x80 */
    Vec4 pos;               /* +0x90 */
};

struct System {
    int unk0;
    Particle *parts;        /* +0x04, PARTICLE_COUNT entries */
    int mode;               /* +0x08 */
    int unkc;
    Vec4 origin;            /* +0x10 */
};

extern "C" int FUN_0001342c(void);                                /* rand() */
extern "C" void FUN_0004d280(Mat4 *, const Mat4 *, float);        /* rotate about x */
extern "C" void FUN_0004d2d4(Mat4 *, const Mat4 *, float);        /* rotate about y */
extern "C" void FUN_0004d328(Mat4 *, const Mat4 *, float);        /* rotate about z */
extern "C" float FUN_001cdda8(const Vec4 *, const Vec4 *);        /* 3-component dot */
extern "C" Vec4 FUN_000542a0(const Vec4 *, float);                /* v * s */
extern "C" Vec4 *FUN_00054330(Vec4 *, const Vec4 *);              /* Vec4 assignment */
extern "C" Vec4 FUN_0021986c(const Vec4 *, const Vec4 *);         /* a + b */
extern "C" void FUN_002198b4(Particle *);                         /* out-of-line Init */
extern "C" Vec4 *FUN_00219968(Vec4 *, const Vec4 *);              /* a += b */
extern "C" Vec4 *FUN_00219998(Vec4 *, const Vec4 *);              /* a -= b */

static inline void Init(Particle *p)
{
    /* Place the particle at a random x/z position on the y = -3.5 plane. */
    float rx = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;
    float rz = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;

    p->pos.x = rx;
    p->pos.y = -3.5f;
    p->pos.z = rz;
    p->pos.w = 0.0f;
}

/* One simulation step: random spin, damped velocity, move, respawn when the particle reaches y >= 0. */
static inline void Step(System *self, Particle *p)
{
    FUN_0004d280(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    FUN_0004d2d4(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    FUN_0004d328(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    p->vel.y += 0.0125f;
    Vec4 t = FUN_000542a0(&p->m.r1, FUN_001cdda8(&p->m.r1, &p->vel) * 0.9f);
    FUN_00219998(&p->vel, &t);
    FUN_00219968(&p->pos, &p->vel);
    if (p->pos.y >= 0.0f) {
        FUN_002198b4(p);
    }
    Vec4 u = FUN_0021986c(&self->origin, &p->pos);
    FUN_00054330(&p->m.r3, &u);
}

extern "C" void FUN_00219a50(System *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case PARTICLE_MODE_WARMUP:
        for (int i = 0; i < PARTICLE_COUNT; i++) {
            Init(&self->parts[i]);
            Step(self, &self->parts[i]);
            Step(self, &self->parts[i]);
            Step(self, &self->parts[i]);
        }
        self->mode = PARTICLE_MODE_RUN;
        break;
    case PARTICLE_MODE_RUN:
        break;
    case PARTICLE_MODE_REINIT:
        for (int i = 0; i < PARTICLE_COUNT; i++) {
            Init(&self->parts[i]);
        }
        self->mode = PARTICLE_MODE_RUN;
        break;
    case PARTICLE_MODE_3:
        break;
    }
}
