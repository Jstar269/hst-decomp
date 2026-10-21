/* HSTMATCH module=EBOOT.BIN start=0x002038ec end=0x00203ba8 symbol=FUN_002038ec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the global camera pointer is read twice (the Cam* local is dead before the first call, so the C copy reloads DAT_003313c4), the Vec4 temporaries are named locals declared B, C, D, E (retail slots 80/64/48/32) with helper results written straight into the members, `len <= 0.0f` -> `len = 1.0f`, both thresholds are `if (!(t < 0.01f))` (c.lt.s/bc1t; `t >= 0.01f` gives c.nge), `float sc = 192.0f * t` keeps the product in a fresh register, and the double expression `0.15f + 0.85f * ((double)f10 / 1.5707963267948966)` compiles to the libm soft-float calls; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Cam {
    char pad0[0x1d0];
    Vec4 v1d0;
    Vec4 v1e0;
};

struct Obj {
    Vec4 v0;
    float f10;
    char pad14[4];
    int f18;
    char pad1c[0xdc - 0x1c];
    float fdc;
    float fe0;
    char pade4[0xf4 - 0xe4];
    float ff4;
    char padf8[0x4e4 - 0xf8];
    unsigned char b4e4;
    char pad4e5[0x4f0 - 0x4e5];
    Vec4 v4f0;
    Vec4 v500;
    float f510;
    float f514;
    int f518;
    int f51c;
};

extern "C" {
extern Cam *DAT_003313c4;
float FUN_0000c6dc(float y, float x);
float FUN_0000bc34(float x);
float FUN_0000bf34(float x);
void FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022450(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
void FUN_00203dcc(Obj *self, int a, int b);
float sqrtf(float);
}

extern "C" void FUN_002038ec(Obj *self)
{
    self->b4e4 = 0;
    Cam *c = DAT_003313c4;
    float x = c->v1e0.x;
    float z = c->v1e0.z;
    float y = c->v1e0.y;
    float a = FUN_0000c6dc(x, z);
    float b = FUN_0000c6dc(-y, sqrtf(x * x + z * z));
    float sb = FUN_0000bc34(-b);
    float h = 1.5707964f - a;
    float sh = FUN_0000bc34(h);
    float ch = FUN_0000bf34(h);
    Vec4 B;
    B.x = sh * sb;
    B.y = FUN_0000bf34(-b);
    B.z = ch * sb;
    Vec4 C = DAT_003313c4->v1d0;
    Vec4 D;
    Vec4 E;
    FUN_00022498(&D, &self->v0, self->fe0);
    FUN_00022418(&self->v500, &C, &D);
    FUN_00022498(&E, &B, self->fdc);
    FUN_00022418(&E, &E, &C);
    FUN_00022434(&self->v4f0, &E, &self->v500);
    FUN_00022498(&E, &self->v4f0, -1.0f);
    float dot = FUN_000224d8(&E, &B);
    FUN_00022450(&E, &self->v4f0, &self->v4f0);
    float len = sqrtf(E.z + (E.x + E.y));
    if (len <= 0.0f)
        len = 1.0f;
    float t = dot / len;
    self->f510 = t;
    if (!(t < 0.01f)) {
        t = t - self->ff4;
        if (!(t < 0.01f)) {
            self->b4e4 = 1;
            self->f514 = 0.15f + 0.85f * ((double)self->f10 / 1.5707963267948966);
            float sc = 192.0f * t;
            int n = (int)sc;
            self->f518 = n;
            if (n > 128)
                self->f518 = 128;
            int m = (int)(sc * self->f514);
            self->f51c = m;
            if (m > 128)
                self->f51c = 128;
            FUN_00203dcc(self, self->f18, 1);
            FUN_00203dcc(self, self->f18, 0);
        }
    }
}
