/* HSTMATCH module=EBOOT.BIN start=0x00244188 end=0x00244308 symbol=FUN_00244188 lang=c++ */
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

extern Globals *DAT_003313c4;
extern Ctx *DAT_00340284;
extern "C" void FUN_00055724(void *, void *);
extern "C" Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}
extern "C" float FUN_00055768(void *);
extern "C" float FUN_000224d8(Vec4 *, Vec4 *);
extern "C" void FUN_0005f1e8(void *, int);

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

extern "C" void FUN_00244188(Self *self) {
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
    FUN_00055724(&q, &self->f60);
    Vec4 c;
    c.x = DAT_003313c4->f1d0.x;
    c.y = DAT_003313c4->f1d0.y;
    c.z = DAT_003313c4->f1d0.z;
    c.w = DAT_003313c4->f1d0.w;
    Vec4 v = Sub(c, q);
    float ang = FUN_00055768(&self->f60);
    float dist = FUN_000224d8(&v, &v);
    if (DAT_00340284->f8c == 2) {
        float d = 3.0f + ang;
        if (d * d < dist) FUN_0005f1e8(&self->f60, 0);
    } else {
        FUN_0005f1e8(&self->f60, 0);
    }
}
