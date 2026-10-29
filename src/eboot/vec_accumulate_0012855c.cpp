/* HSTMATCH module=EBOOT.BIN start=0x0012855c end=0x00128764 symbol=FUN_0012855c lang=c++ */
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
    float weight_a;
    float weight_b;
    char pad158[8];
    Vec4 move;
    char pad170[0x194 - 0x170];
    int mode;
    char pad198[0x1b0 - 0x198];
    Vec4 pos;
    char pad1c0[0x200 - 0x1c0];
    Vec4 dir_a;
    Vec4 dir_b;
};

extern "C" {
extern float DAT_002da3b0;
extern float DAT_002da3a8;
extern float DAT_002da3a0;
void FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
void FUN_00022518(Vec4 *out, const Vec4 *v);
void FUN_00128c94(Obj *self, Vec4 *v, int n);
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

/* Like the follow step without the state changes: weighted sum of two directions, clamped length, position advance. */
extern "C" void FUN_0012855c(Obj *self)
{
    float weight = self->weight_a;
    self->move = Combine(Scale(self->dir_a, weight), Scale(self->dir_b, self->weight_b));
    float len_sq = FUN_000224d8(&self->move, &self->move);
    if (FUN_000224d8(&self->move, &self->move) > 1e-05f) {
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
        if (self->mode == 5)
            self->pos.Add(Scale(self->move, DAT_002da3a8));
        else
            self->pos.Add(Scale(self->move, DAT_002da3a0));
        FUN_00128c94(self, &self->move, 0);
    }
}
