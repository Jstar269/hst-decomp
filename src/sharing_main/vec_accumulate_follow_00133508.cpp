/* HSTMATCH module=hstp_trans_main.prx start=0x00133508 end=0x001337cc symbol=FUN_00133508 lang=c++ */
/* Clone of src/eboot/vec_accumulate_follow_00128298.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: same Vec4 helpers as 0x12855c (`#pragma inline_depth(8)`, aligned(16) Vec4 with copy ctor, by-value inline Scale/Combine/Add; arguments of Combine evaluate right to left), the two state tests that retail compiles as compare chains are one-case and two-case `switch`es (`switch (state) { case 4: case 5: ... }`, `switch (state) { case 0: ... }`), the final branch is `if (FUN_00137630(1) != 0) {5} else {4}`; names and types await human review. */
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
    Vec4 v170;
    Vec4 v180;
    int state;
    char pad194[0x1b0 - 0x194];
    Vec4 v1b0;
};

extern "C" {
extern float DAT_00381430;
extern float DAT_00381428;
extern float DAT_00381420;
extern float DAT_0038142c;
void FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
void FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
void FUN_00022540(Vec4 *out, const Vec4 *v);
void FUN_00133f04(Obj *self, Vec4 *v, int n);
void FUN_001354c4(Obj *self, int a, int b, int c);
int FUN_00137630(int a);
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

extern "C" void FUN_00133508(Obj *self)
{
    float s0 = self->f150;
    self->v160 = Combine(Scale(self->v170, s0), Scale(self->v180, self->f154));
    float l2 = FUN_00022500(&self->v160, &self->v160);
    if (self->state == 5 && l2 < DAT_0038142c * DAT_0038142c) {
        FUN_001354c4(self, 4, -1, 0);
    }
    if (l2 < 0.0001f) {
        switch (self->state) {
        case 4:
        case 5:
            FUN_001354c4(self, 0, -1, 0);
            break;
        }
    } else {
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
        if (self->state == 5)
            self->v1b0.Add(Scale(self->v160, DAT_00381428));
        else
            self->v1b0.Add(Scale(self->v160, DAT_00381420));
        FUN_00133f04(self, &self->v160, 0);
        switch (self->state) {
        case 0:
            if (FUN_00137630(1) != 0)
                FUN_001354c4(self, 5, -1, 0);
            else
                FUN_001354c4(self, 4, -1, 0);
            break;
        }
    }
}
