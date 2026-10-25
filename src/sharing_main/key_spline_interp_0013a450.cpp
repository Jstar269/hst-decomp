/* HSTMATCH module=hstp_trans_main.prx start=0x0013a450 end=0x0013a7a0 symbol=FUN_0013a450 lang=c++ */
/* Clone of src/eboot/key_spline_interp_0012eef8.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

struct Vec3 { float x, y, z; };

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

struct Key {
    Vec4 r0, r1, r2, r3;
    Vec3 s;
    float pad;
};

extern "C" {
Vec4 *FUN_000226ec(Vec4 *, const Key *);
Vec4 *FUN_000229c4(Vec4 *, const Vec4 *, const Vec4 *, float);
Key *FUN_00022960(Key *, const Vec4 *);
Mat4 *FUN_00022598(Mat4 *, const Basis *, const Mat4 *);
Vec4 *FUN_00022570(Vec4 *, const Mat4 *, const Vec4 *);
}

extern Mat4 DAT_002d11e0;

extern "C" void FUN_0013a450(float t, Key *out, Key *keys)
{
    int i = (int)t;
    t -= (float)i;
    float t2 = t * t;
    float t3 = t2 * t;
    Vec4 q0;
    FUN_000226ec(&q0, &keys[i]);
    Vec4 q1 = q0;
    Vec4 q2;
    FUN_000226ec(&q2, &keys[i + 1]);
    Vec4 q3 = q2;
    Vec4 a, b, c, d, e, f;
    FUN_000229c4(&a, &q0, &q1, t);
    FUN_000229c4(&b, &q1, &q2, t);
    FUN_000229c4(&c, &q2, &q3, t);
    FUN_000229c4(&d, &a, &b, t);
    FUN_000229c4(&e, &b, &c, t);
    FUN_000229c4(&f, &d, &e, t);
    FUN_00022960(out, &f);
    Mat4 m;
    Vec4 r;
    {
        Vec4 p0 = keys[i].r3;
        Vec4 p1 = keys[i + 1].r3;
        Basis g(p0, p0, p1, p1);
        FUN_00022598(&m, &g, &DAT_002d11e0);
        Vec4 tv(t3, t2, t, 1.0f);
        FUN_00022570(&out->r3, &m, &tv);
    }
    {
        Vec4 s0(keys[i].s.x, keys[i].s.y, keys[i].s.z, 0.0f);
        Vec4 s1(keys[i + 1].s.x, keys[i + 1].s.y, keys[i + 1].s.z, 0.0f);
        Basis g(s0, s0, s1, s1);
        FUN_00022598(&m, &g, &DAT_002d11e0);
        Vec4 tv(t3, t2, t, 1.0f);
        FUN_00022570(&r, &m, &tv);
        out->s.x = r.x;
        out->s.y = r.y;
        out->s.z = r.z;
    }
}
