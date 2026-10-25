/* HSTMATCH module=hstp_trans_main.prx start=0x002362ec end=0x00236534 symbol=FUN_002362ec lang=c++ */
/* Clone of src/eboot/place_random_yaw_00226d78.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
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

extern World *DAT_003e95e0;
extern Mat4 DAT_002cc260;

extern "C" {
void FUN_00055be8(void *track, Vec4 *p);
void FUN_0004d64c(float angle, Mat4 *out, Mat4 *in);
}

static inline int Rand()
{
    unsigned int seed = DAT_003e95e0->seed * 0x343fd + 0x269ec3;
    DAT_003e95e0->seed = seed;
    return (seed >> 16) & 0x7fff;
}

static inline void Copy(Vec4 &d, const Vec4 &s)
{
    d.x = s.x;
    d.y = s.y;
    d.z = s.z;
    d.w = s.w;
}

extern "C" void FUN_002362ec(Self *self, Vec4 p)
{
    if (self->locked == 0) {
        FUN_00055be8(self->trackA, &p);
        int m = self->mode;
        if (m == 1 || m == 23 || m == 24 || m == 25 || m == 11 || m == 15)
            FUN_00055be8(self->trackB, &p);
    } else {
        FUN_00055be8(self->trackA, &p);
    }
    Copy(self->pos, p);
    Copy(self->home, self->pos);
    self->mat = DAT_002cc260;
    self->angle = Rand() % 360;
    FUN_0004d64c(0.017453292f * self->angle, &self->mat, &self->mat);
    Copy(self->mat.r3, self->home);
}
