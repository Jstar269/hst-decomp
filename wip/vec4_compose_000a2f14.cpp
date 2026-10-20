/* HSTMATCH module=EBOOT.BIN start=0x000a2f14 end=0x000a3018 symbol=FUN_000a2f14 lang=c++ */
// NEAR MISS (65/65 words, 14 differ, first at +0x48): every instruction matches, only the three stack slots are
// rotated. Ours d=48, Scale-arg-copy=32, Scale-ret=16; retail d=16, Scale-ret=32, Scale-arg-copy=48.
// Ruled out this session (20 compiles): all 6 declaration permutations of u/t/d (14 or 19 differ, never the
// retail rotation); by-value-returning inline wrappers for both steps with reference params (83 words, +1 slot);
// with pointer params (83); with non-const refs (83); Cross as plain `static` (MISPLACED, became out of line);
// by-value params (105); nested `Scale(Cross(va,vb),0.93f)` with ref Cross + value Scale (83); d=Cross(..) then
// Scale(d) with those params (91); `u = Scale(...)` assigned instead of initialised (73). Every wrapper form is
// structurally right (ret temp -> named local copy, argument reused directly) but costs one extra 32-byte slot,
// which shifts all offsets; the direct-call version below is the only 65/65 shape found.

struct Vec4 { float x, y, z, w; };

extern "C" void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern "C" void FUN_00022498(Vec4 *out, const Vec4 *a, float s);
extern "C" void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);

static inline Vec4 Scale(Vec4 v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

extern "C" void FUN_000a2f14(Vec4 *out, const Vec4 *a, const Vec4 *b)
{
    Vec4 va = *a;
    Vec4 vb = *b;
    Vec4 u;
    Vec4 t;
    Vec4 d;
    FUN_00022434(&d, &va, &vb);
    t = Scale(d, 0.93f);
    u = t;
    u.y = 0.0f;
    FUN_00022418(&va, &va, &u);
    va.w = 1.0f;
    *out = va;
}
// near miss from lane ds1 (unreviewed)
