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
    float weight_a;
    float weight_b;
    char pad158[8];
    Vec4 move;
    Vec4 dir_a;
    Vec4 dir_b;
    int state;
    char pad194[0x1b0 - 0x194];
    Vec4 pos;
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

/* Steers the avatar: the move vector is a weighted sum of two directions; short vectors stop the movement,
   otherwise the position advances and the heading is updated. */
extern "C" void FUN_00128298(Obj *self)
{
    float weight = self->weight_a;
    self->move = Combine(Scale(self->dir_a, weight), Scale(self->dir_b, self->weight_b));
    float len_sq = FUN_000224d8(&self->move, &self->move);
    if (self->state == 5 && len_sq < DAT_002da3ac * DAT_002da3ac) {
        FUN_0012a254(self, 4, -1, 0);
    }
    if (len_sq < 0.0001f) {
        switch (self->state) {
        case 4:
        case 5:
            FUN_0012a254(self, 0, -1, 0);
            break;
        }
    } else {
        float len = sqrtf(len_sq);
        if (len > 1.0f) {
            FUN_00022518(&self->move, &self->move);
            self->move.w = 0.0f;
        }
        if (len < DAT_002da3b0) {
            FUN_00022518(&self->move, &self->move);
            self->move.w = 0.0f;
            FUN_00022498(&self->move, &self->move, DAT_002da3b0);
        }
        if (self->state == 5)
            self->pos.Add(Scale(self->move, DAT_002da3a8));
        else
            self->pos.Add(Scale(self->move, DAT_002da3a0));
        FUN_00128c94(self, &self->move, 0);
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
