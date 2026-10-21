/* HSTMATCH module=EBOOT.BIN start=0x000a2f14 end=0x000a3018 symbol=FUN_000a2f14 lang=c++ */
/* Hand-written reconstruction from the disassembly (started from the near-miss wip of lane ds1); exact match verified; names and types await human review. */
/* va/vb are BY-VALUE parameters (the callee copies them into its frame); matching idioms: Vec4 has a user default constructor (copy elision of the returned temporaries) and the out-of-line VFPU helpers 0x22434 (sub), 0x22498 (scale), 0x22418 (add) are wrapped by inline value-returning Sub/Scale taking const references. */
struct Vec4 { float x, y, z, w; Vec4() {} };

extern "C" void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern "C" void FUN_00022498(Vec4 *out, const Vec4 *a, float s);
extern "C" void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

extern "C" void FUN_000a2f14(Vec4 *out, Vec4 va, Vec4 vb)
{
    Vec4 u = Scale(Sub(va, vb), 0.93f);
    u.y = 0.0f;
    FUN_00022418(&va, &va, &u);
    va.w = 1.0f;
    *out = va;
}
