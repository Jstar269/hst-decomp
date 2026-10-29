/* HSTMATCH module=hstp_trans_main.prx start=0x00228f68 end=0x002294b8 symbol=FUN_00228f68 lang=c++ */
/* Hand-written reconstruction from the disassembly; Init/Step are static inline helpers expanded in place (Step's respawn calls the out-of-line copy of Init, FUN_00228dcc, directly: MWCC does not inline a call made from an inlined body); exact match verified; names and types await human review. */
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
extern "C" void FUN_0004d5f8(Mat4 *, const Mat4 *, float);        /* rotate about x */
extern "C" void FUN_0004d64c(Mat4 *, const Mat4 *, float);        /* rotate about y */
extern "C" void FUN_0004d6a0(Mat4 *, const Mat4 *, float);        /* rotate about z */
extern "C" float FUN_001dc484(const Vec4 *, const Vec4 *);        /* 3-component dot */
extern "C" Vec4 FUN_00054dec(const Vec4 *, float);                /* v * s */
extern "C" Vec4 *FUN_00054e7c(Vec4 *, const Vec4 *);              /* Vec4 assignment */
extern "C" Vec4 FUN_00228d84(const Vec4 *, const Vec4 *);         /* a + b */
extern "C" void FUN_00228dcc(Particle *);                         /* out-of-line Init */
extern "C" Vec4 *FUN_00228e80(Vec4 *, const Vec4 *);              /* a += b */
extern "C" Vec4 *FUN_00228eb0(Vec4 *, const Vec4 *);              /* a -= b */

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
    FUN_0004d5f8(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    FUN_0004d64c(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    FUN_0004d6a0(&p->m, &p->m, p->spin * (float)FUN_0001342c() / 2147483648.0f);
    p->vel.y += 0.0125f;
    Vec4 t = FUN_00054dec(&p->m.r1, FUN_001dc484(&p->m.r1, &p->vel) * 0.9f);
    FUN_00228eb0(&p->vel, &t);
    FUN_00228e80(&p->pos, &p->vel);
    if (p->pos.y >= 0.0f) {
        FUN_00228dcc(p);
    }
    Vec4 u = FUN_00228d84(&self->origin, &p->pos);
    FUN_00054e7c(&p->m.r3, &u);
}

extern "C" void FUN_00228f68(System *self, int mode)
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
