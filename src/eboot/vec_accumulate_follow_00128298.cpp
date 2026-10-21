/* HSTMATCH module=EBOOT.BIN start=0x00128298 end=0x0012855c symbol=FUN_00128298 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: same Vec4 helpers as 0x12855c (`#pragma inline_depth(8)`, aligned(16) Vec4 with copy ctor, by-value inline Scale/Combine/Add; arguments of Combine evaluate right to left), the two state tests that retail compiles as compare chains are one-case and two-case `switch`es (`switch (state) { case 4: case 5: ... }`, `switch (state) { case 0: ... }`), the final branch is `if (FUN_0012c1c4(1) != 0) {5} else {4}`; names and types await human review. */
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
extern float DAT_002da3b0;
extern float DAT_002da3a8;
extern float DAT_002da3a0;
extern float DAT_002da3ac;
void FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
void FUN_00022518(Vec4 *out, const Vec4 *v);
void FUN_00128c94(Obj *self, Vec4 *v, int n);
void FUN_0012a254(Obj *self, int a, int b, int c);
int FUN_0012c1c4(int a);
float sqrtf(float);
}

inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}
inline Vec4 Combine(Vec4 a, Vec4 b)
{
    Vec4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}
inline void Vec4::Add(Vec4 v)
{
    FUN_00022418(this, this, &v);
}

extern "C" void FUN_00128298(Obj *self)
{
    float s0 = self->f150;
    self->v160 = Combine(Scale(self->v170, s0), Scale(self->v180, self->f154));
    float l2 = FUN_000224d8(&self->v160, &self->v160);
    if (self->state == 5 && l2 < DAT_002da3ac * DAT_002da3ac) {
        FUN_0012a254(self, 4, -1, 0);
    }
    if (l2 < 0.0001f) {
        switch (self->state) {
        case 4:
        case 5:
            FUN_0012a254(self, 0, -1, 0);
            break;
        }
    } else {
        float len = sqrtf(l2);
        if (len > 1.0f) {
            FUN_00022518(&self->v160, &self->v160);
            self->v160.w = 0.0f;
        }
        if (len < DAT_002da3b0) {
            FUN_00022518(&self->v160, &self->v160);
            self->v160.w = 0.0f;
            FUN_00022498(&self->v160, &self->v160, DAT_002da3b0);
        }
        if (self->state == 5)
            self->v1b0.Add(Scale(self->v160, DAT_002da3a8));
        else
            self->v1b0.Add(Scale(self->v160, DAT_002da3a0));
        FUN_00128c94(self, &self->v160, 0);
        switch (self->state) {
        case 0:
            if (FUN_0012c1c4(1) != 0)
                FUN_0012a254(self, 5, -1, 0);
            else
                FUN_0012a254(self, 4, -1, 0);
            break;
        }
    }
}
