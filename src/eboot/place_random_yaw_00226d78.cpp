/* HSTMATCH module=EBOOT.BIN start=0x00226d78 end=0x00226fc0 symbol=FUN_00226d78 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

struct Self {
    char pad0[0x40];
    Vec4 pos;
    Vec4 home;
    Mat4 mat;
    int locked;
    char padA4[0xc];
    char trackA[0x1b0];
    char trackB[0x1c4];
    int angle;
    int mode;
};
struct World {
    char pad[0x1360];
    unsigned int seed;
};

#define DEG_TO_RAD 0.017453292f
#define YAW_STEPS 360 /* whole degrees in a full turn */

extern World *DAT_003402a0;
extern Mat4 DAT_002bc410;

extern "C" {
void FUN_000550c8(void *track, Vec4 *p);
void FUN_0004d2d4(float angle, Mat4 *out, Mat4 *in);
}

/* Linear congruential generator on the world seed; returns 15 bits. */
static inline int Rand()
{
    unsigned int seed = DAT_003402a0->seed * 0x343fd + 0x269ec3;
    DAT_003402a0->seed = seed;
    return (seed >> 16) & 0x7fff;
}

static inline void Copy(Vec4 &d, const Vec4 &s)
{
    d.x = s.x;
    d.y = s.y;
    d.z = s.z;
    d.w = s.w;
}

/* Moves the object to position p (tracking it on one or both tracks), then gives it a random yaw about its own position. */
extern "C" void FUN_00226d78(Self *self, Vec4 p)
{
    if (self->locked == 0) {
        FUN_000550c8(self->trackA, &p);
        int m = self->mode;
        if (m == 1 || m == 23 || m == 24 || m == 25 || m == 11 || m == 15)
            FUN_000550c8(self->trackB, &p);
    } else {
        FUN_000550c8(self->trackA, &p);
    }
    Copy(self->pos, p);
    Copy(self->home, self->pos);
    self->mat = DAT_002bc410; /* start from the reference matrix */
    self->angle = Rand() % YAW_STEPS;
    FUN_0004d2d4(DEG_TO_RAD * self->angle, &self->mat, &self->mat);
    Copy(self->mat.r3, self->home);
}
