/* HSTMATCH module=hstp_trans_main.prx start=0x001e5c84 end=0x001e5e00 symbol=FUN_001e5c84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Cubic curve segment evaluation: picks segment i = (int)t (clamped to count/stride - 1) of a key-row table, builds a
   4x4 basis from its four Vec4 rows (by-value constructor arguments: the four batch-copied stack temporaries; the
   out-of-line Vec4 default constructor and operator= are FUN_00057f98/FUN_00054e7c, as in the sibling
   src/sharing_main/key_spline_interp_0013a450.cpp whose Vec4/Basis definitions are reused), multiplies it with the
   curve's basis matrix into the curve matrix (FUN_00022598, VFPU vmmul) and transforms (t^3, t^2, t, 1) by it into
   out (FUN_00022570, VFPU vtfm4). */
struct Vec4;
extern "C" {
Vec4 *FUN_00057f98(Vec4 *);
Vec4 *FUN_00054e7c(Vec4 *, const Vec4 *);
}

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

struct Basis {
    Vec4 r0, r1, r2, r3;
    Basis(Vec4 a, Vec4 b, Vec4 c, Vec4 d)
    {
        FUN_00057f98(&r0);
        FUN_00057f98(&r1);
        FUN_00057f98(&r2);
        FUN_00057f98(&r3);
        FUN_00054e7c(&r0, &a);
        FUN_00054e7c(&r1, &b);
        FUN_00054e7c(&r2, &c);
        FUN_00054e7c(&r3, &d);
    }
};

struct Curve {
    Mat4 m;
    Mat4 *basis;
};

extern "C" {
Mat4 *FUN_00022598(Mat4 *, const Basis *, const Mat4 *);
Vec4 *FUN_00022570(Vec4 *, const Mat4 *, const Vec4 *);
}

extern "C" void FUN_001e5c84(float t, Curve *c, Vec4 *out, const Vec4 *keys, unsigned count, unsigned stride)
{
    int i = (int)t;
    unsigned n = count / stride;
    if (i >= n)
        i = n - 1;
    t -= (float)i;
    const Vec4 *k = &keys[i * stride];
    Basis g(k[0], k[1], k[2], k[3]);
    FUN_00022598(&c->m, &g, c->basis);
    float t2 = t * t;
    float t3 = t2 * t;
    Vec4 tv(t3, t2, t, 1.0f);
    FUN_00022570(out, &c->m, &tv);
}
