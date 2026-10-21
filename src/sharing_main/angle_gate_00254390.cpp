/* HSTMATCH module=hstp_trans_main.prx start=0x00254390 end=0x00254510 symbol=FUN_00254390 lang=c++ */
/* Clone of src/eboot/angle_gate_00244188.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Globals {
    char pad[0x1d0];
    Vec4 f1d0;
};

struct Ctx {
    char pad[0x8c];
    int f8c;
};

extern Globals *DAT_003da704;
extern Ctx *DAT_003e95c4;
extern "C" void FUN_000562d0(void *, void *);
extern "C" Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}
extern "C" float FUN_00056314(void *);
extern "C" float FUN_00022500(Vec4 *, Vec4 *);
extern "C" void FUN_0005ffd8(void *, int);

struct Self {
    char pad0[0x3c];
    unsigned char f3c;
    int f40;
    char pad1[0x10];
    unsigned char f54;
    char pad2[0xb];
    Vec4 f60;
    char pad3[0x1f0];
    int f260;
    char pad4[0x48];
    int f2ac;
};

extern "C" void FUN_00254390(Self *self) {
    if (self->f3c == 0) return;
    if ((unsigned int)(self->f2ac - 4) < 2) {
        if (self->f40 == 1) return;
    }
    if (self->f40 == 1) {
        int s = self->f260;
        if (s == 10 || s == 9 || s == 7 || s == 44) return;
    }
    if (self->f54 == 0) return;
    Vec4 q;
    FUN_000562d0(&q, &self->f60);
    Vec4 c;
    c.x = DAT_003da704->f1d0.x;
    c.y = DAT_003da704->f1d0.y;
    c.z = DAT_003da704->f1d0.z;
    c.w = DAT_003da704->f1d0.w;
    Vec4 v = Sub(c, q);
    float ang = FUN_00056314(&self->f60);
    float dist = FUN_00022500(&v, &v);
    if (DAT_003e95c4->f8c == 2) {
        float d = 3.0f + ang;
        if (d * d < dist) FUN_0005ffd8(&self->f60, 0);
    } else {
        FUN_0005ffd8(&self->f60, 0);
    }
}
