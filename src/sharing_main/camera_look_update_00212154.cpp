/* HSTMATCH module=hstp_trans_main.prx start=0x00212154 end=0x00212410 symbol=FUN_00212154 lang=c++ */
/* Clone of src/eboot/camera_look_update_002038ec.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the global camera pointer is read twice (the Cam* local is dead before the first call, so the C copy reloads DAT_003da704), the Vec4 temporaries are named locals declared B, C, D, E (retail slots 80/64/48/32) with helper results written straight into the members, `len <= 0.0f` -> `len = 1.0f`, both thresholds are `if (!(t < 0.01f))` (c.lt.s/bc1t; `t >= 0.01f` gives c.nge), `float sc = 192.0f * t` keeps the product in a fresh register, and the double expression `0.15f + 0.85f * ((double)f10 / 1.5707963267948966)` compiles to the libm soft-float calls; names and types await human review. */
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
extern Cam *DAT_003da704;
float FUN_0000c6f4(float y, float x);
float FUN_0000bc4c(float x);
float FUN_0000bf4c(float x);
void FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
void FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022478(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
void FUN_00212634(Obj *self, int a, int b);
float sqrtf(float);
}

extern "C" void FUN_00212154(Obj *self)
{
    self->b4e4 = 0;
    Cam *c = DAT_003da704;
    float x = c->v1e0.x;
    float z = c->v1e0.z;
    float y = c->v1e0.y;
    float a = FUN_0000c6f4(x, z);
    float b = FUN_0000c6f4(-y, sqrtf(x * x + z * z));
    float sb = FUN_0000bc4c(-b);
    float h = 1.5707964f - a;
    float sh = FUN_0000bc4c(h);
    float ch = FUN_0000bf4c(h);
    Vec4 B;
    B.x = sh * sb;
    B.y = FUN_0000bf4c(-b);
    B.z = ch * sb;
    Vec4 C = DAT_003da704->v1d0;
    Vec4 D;
    Vec4 E;
    FUN_000224c0(&D, &self->v0, self->fe0);
    FUN_00022440(&self->v500, &C, &D);
    FUN_000224c0(&E, &B, self->fdc);
    FUN_00022440(&E, &E, &C);
    FUN_0002245c(&self->v4f0, &E, &self->v500);
    FUN_000224c0(&E, &self->v4f0, -1.0f);
    float dot = FUN_00022500(&E, &B);
    FUN_00022478(&E, &self->v4f0, &self->v4f0);
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
            FUN_00212634(self, self->f18, 1);
            FUN_00212634(self, self->f18, 0);
        }
    }
}
