/* HSTMATCH module=hstp_trans_main.prx start=0x001337cc end=0x001339d4 symbol=FUN_001337cc lang=c++ */
/* Clone of src/eboot/vec_accumulate_0012855c.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: `#pragma inline_depth(8)` so that the by-value Vec4 parameter copies of the inline Combine/Add are expanded (their copy ctor otherwise stays an out-of-line call), by-value inline parameters (Combine(Vec4,Vec4), Vec4::Add(Vec4)) give the retail slot layout; names and types await human review. */
#pragma inline_depth(8)
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    void Add(Vec4 v);
} __attribute__((aligned(16)));

struct Obj {
    char pad0[0x150];
    float f150;
    float f154;
    char pad158[8];
    Vec4 v160;
    char pad170[0x194 - 0x170];
    int mode;
    char pad198[0x1b0 - 0x198];
    Vec4 v1b0;
    char pad1c0[0x200 - 0x1c0];
    Vec4 v200;
    Vec4 v210;
};

extern "C" {
extern float DAT_00381430;
extern float DAT_00381428;
extern float DAT_00381420;
void FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
void FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
void FUN_00022540(Vec4 *out, const Vec4 *v);
void FUN_00133f04(Obj *self, Vec4 *v, int n);
float sqrtf(float);
}

inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_000224c0(&r, &v, s);
    return r;
}
inline Vec4 Combine(Vec4 a, Vec4 b)
{
    Vec4 r;
    FUN_00022440(&r, &a, &b);
    return r;
}
inline void Vec4::Add(Vec4 v)
{
    FUN_00022440(this, this, &v);
}

extern "C" void FUN_001337cc(Obj *self)
{
    float s0 = self->f150;
    self->v160 = Combine(Scale(self->v200, s0), Scale(self->v210, self->f154));
    float l2 = FUN_00022500(&self->v160, &self->v160);
    if (FUN_00022500(&self->v160, &self->v160) > 1e-05f) {
        float len = sqrtf(l2);
        if (len > 1.0f) {
            FUN_00022540(&self->v160, &self->v160);
            self->v160.w = 0.0f;
        }
        if (len < DAT_00381430) {
            FUN_00022540(&self->v160, &self->v160);
            self->v160.w = 0.0f;
            FUN_000224c0(&self->v160, &self->v160, DAT_00381430);
        }
        if (self->mode == 5)
            self->v1b0.Add(Scale(self->v160, DAT_00381428));
        else
            self->v1b0.Add(Scale(self->v160, DAT_00381420));
        FUN_00133f04(self, &self->v160, 0);
    }
}
