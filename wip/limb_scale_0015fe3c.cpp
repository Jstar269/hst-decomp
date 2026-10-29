/* HSTMATCH module=EBOOT.BIN start=0x0015fe3c end=0x00160058 symbol=FUN_0015fe3c lang=c++ */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

extern "C" float FUN_0000c000(float);
extern "C" void FUN_00022498(Vec4 *out, const Vec4 *in, float s);
extern "C" void FUN_00022518(Vec4 *out, const Vec4 *in);
extern "C" void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern const float DAT_002de878;
extern const float DAT_002de87c;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Obj {
    unsigned char pad00[0x30];
    float f30[4];
    Vec4 m40;
    float f50;
    unsigned char pad54[0x80 - 0x54];
    float f80;
};

extern "C" void FUN_0015fe3c(float angle, Obj *self)
{
    float c = Clamp(angle, DAT_002de878, DAT_002de87c);
    float sc = self->f50;
    float k = sc * FUN_0000c000((self->f80 * 0.017453292f) / 2.0f);
    Vec4 y;
    Vec4 t;
    Vec4 m;
    Vec4 b;
    Vec4 z;
    Vec4 s;
    Vec4 w;
    Vec4 v;
    Vec4 n;
    Vec4 u;
    Vec4 x;
    Vec4 a;

    k = k / FUN_0000c000((c * 0.017453292f) / 2.0f);

    float s0 = self->f50;
    v = Vec4(-self->f30[0], -self->f30[1], -self->f30[2], -self->f30[3]);
    FUN_00022498(&a, &v, s0);
    b = a;
    FUN_00022518(&n, &b);
    n.w = 0.0f;
    m = n;
    FUN_00022498(&s, &m, k);
    t = s;
    FUN_00022498(&u, (const Vec4 *)self->f30, self->f50);
    w = u;
    FUN_00022418(&x, &self->m40, &w);
    y = x;
    FUN_00022418(&z, &y, &t);
    Vec4 r = z;
    self->m40 = r;
    self->f80 = c;
}
// lane wf20261026-e01-03: 90 -> 12 words. Fixes: Vec4 locals declared y,t,m,b,z,s,w,v,n,u,x,a (retail slot order,
// first declared = highest slot); negation via a 4-float ctor `v = Vec4(-x,-y,-z,-w)` (right-to-left args give
// retail's w,z,y load order); `n.w = 0.0f; m = n;` (zero stored to both); f50 read into a local before the negation.
// Left: (1) head FPR colouring (4 words): retail keeps 0.017453292f in $f0 and materialises 2.0f after the mul with the
// f21 load in between; ours puts the constant in $f2 (tried r/sc split locals, k*=). (2) final `self->m40 = z` (8 words):
// retail batch +4,+8,+12,+0 (inline-return copy); an inline Add() returning by value gives that batch but moves its
// temp to the frame bottom (44 words); Quad cast / per-field / pointer: still pairs.
// improved by lane wf20261026-e01-03 (unreviewed): 90 -> 12 differing words
// lane sx3: 12 -> 4 differing words. The final `self->m40 = z` copy becomes retail's batched +4,+8,+12,+0 loads by copying THROUGH A LOCAL:
// `Vec4 r = z; self->m40 = r;` (same trick as 0x611d0). Left: the head FPR colouring (4 words): retail issues `lwc1 f21,80(s0)` between `lui 0x4000`
// and the mul and keeps K=0.017453292f in $f0 (2.0f is materialised into $f0 AFTER the mul); ours hoists the 2.0f mtc1 above the mul so K lands in $f2.
// Ruled out (all 4 differ or worse): half-angle in a named local (before/after sc), f80 in a local before/after sc, k = FUN(..); k = sc * k (5), f50 inlined into the call product (9),
// single-literal `f80 * (K / 2.0f)` (110).
// improved by lane sx3 (unreviewed): 12 -> 4 differing words
