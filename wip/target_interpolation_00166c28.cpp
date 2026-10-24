/* HSTMATCH module=EBOOT.BIN start=0x00166c28 end=0x00166ec0 symbol=FUN_00166c28 lang=c++ */

extern "C" {
struct Vec4;
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022498(float s, Vec4 *out, const Vec4 *a);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
float FUN_00022e44(float x);
float FUN_00169f08(const Vec4 *a, const Vec4 *b);
float FUN_00169f24(const Vec4 *a, const Vec4 *b);
}

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4 operator-(const Vec4 &b) const {
        Vec4 r;
        FUN_00022434(&r, this, &b);
        return r;
    }
    Vec4 operator+(const Vec4 &b) const {
        Vec4 r;
        FUN_00022418(&r, this, &b);
        return r;
    }
    Vec4 operator*(float s) const {
        Vec4 r;
        FUN_00022498(s, &r, this);
        return r;
    }
} __attribute__((aligned(16)));

static inline float Length(const Vec4 &v)
{
    return FUN_00022e44(FUN_000224d8(&v, &v));
}

struct Obj166c28 {
    Vec4 p0;          // 0x00
    Vec4 p1;          // 0x10
    Vec4 p2;          // 0x20
    char pad_30[0xc]; // 0x30
    float t;          // 0x3c
    char pad_40[0x30];// 0x40
    Vec4 out_p;       // 0x70
    Vec4 p3;          // 0x80
    float ang1;       // 0x90
    float ang2;       // 0x94
    float ang3;       // 0x98
    float ang4;       // 0x9c
    float len;        // 0xa0
};

extern "C" void FUN_00166c28(Obj166c28 *self)
{
    Vec4 v4;
    Vec4 v3;
    Vec4 v2;
    Vec4 v1;
    Vec4 v6;
    Vec4 v5;
    Vec4 v7;

    v1 = self->p1 - self->p0;
    v2 = self->p0 - v1;
    v3 = self->p2 - v2;
    float len1 = Length(v3);
    v4 = self->p2 - self->p1;
    float len2 = Length(v4);

    if (len2 > len1) {
        if (self->t > 0.0f) {
            self->t = 0.0f;
        }
    }
    if (self->t > 1.0f) {
        self->t = 1.0f;
    }
    if (self->t < 0.0f) {
        self->t = 0.0f;
    }
    float scale = self->t;

    v5 = self->p3 - self->p0;
    v6 = v5 * scale;
    self->out_p = self->p0 + v6;

    self->ang1 = FUN_00169f08(&self->out_p, &self->p3);
    self->ang2 = FUN_00169f24(&self->out_p, &self->p3);
    self->ang3 = FUN_00169f08(&self->out_p, &self->p2);
    self->ang4 = FUN_00169f24(&self->out_p, &self->p2);

    v7 = self->p0 - self->p1;
    self->len = Length(v7);
}

// Differing words: 40/166 words differ.
// All 166 words generated; frame size (272 bytes) and 7 local variable locations match retail exactly.
// All comparisons, float constants, branches, and register colouring match retail 100%.
// The 40 differing words are solely the 8 temporary stack slots (1 addiu + 4 lwc1 per call):
// Retail uses sp offsets 128, 112, 96, 144 for calls 1-4 and 32, 48, 64, 80 for calls 5-8.
// Ours allocates 144, 128, 112, 96, 80, 64, 48, 32 sequentially downwards.
// Ruled out: separate inline helper (increases frame to 336), nested assignments (emits out-of-line operator=),
// non-member vs member operator overloads (no effect on slot ordering).
// near miss from lane ag2 (unreviewed)
