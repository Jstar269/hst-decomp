/* HSTMATCH module=EBOOT.BIN start=0x0012eef8 end=0x0012f248 symbol=FUN_0012eef8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4;
extern "C" {
Vec4 *FUN_00057344(Vec4 *);
Vec4 *FUN_00054330(Vec4 *, const Vec4 *);
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
        FUN_00057344(&r0);
        FUN_00057344(&r1);
        FUN_00057344(&r2);
        FUN_00057344(&r3);
        FUN_00054330(&r0, &a);
        FUN_00054330(&r1, &b);
        FUN_00054330(&r2, &c);
        FUN_00054330(&r3, &d);
    }
};

/* One animation key: a rotation/translation matrix and a scale. */
struct KeyFrame {
    Vec4 r0, r1, r2, r3;
    Vec3 s;
    float pad;
};

extern "C" {
Vec4 *FUN_000226c4(Vec4 *, const KeyFrame *);
Vec4 *FUN_0002299c(Vec4 *, const Vec4 *, const Vec4 *, float);
KeyFrame *FUN_00022938(KeyFrame *, const Vec4 *);
Mat4 *FUN_00022570(Mat4 *, const Basis *, const Mat4 *);
Vec4 *FUN_00022548(Vec4 *, const Mat4 *, const Vec4 *);
}

extern Mat4 DAT_002c0f30;

/* Interpolates between keys[i] and keys[i+1] at time t (integer part = key index): rotation with nested
   interpolation steps, translation and scale with the shared cubic basis. */
extern "C" void FUN_0012eef8(float t, KeyFrame *out, KeyFrame *keys)
{
    int i = (int)t;
    t -= (float)i;  /* fraction between the two keys */
    float t2 = t * t;
    float t3 = t2 * t;  /* powers of t for the cubic basis */
    Vec4 q0;
    FUN_000226c4(&q0, &keys[i]);
    Vec4 q1 = q0;
    Vec4 q2;
    FUN_000226c4(&q2, &keys[i + 1]);
    Vec4 q3 = q2;
    Vec4 a, b, c, d, e, f;
    FUN_0002299c(&a, &q0, &q1, t);
    FUN_0002299c(&b, &q1, &q2, t);
    FUN_0002299c(&c, &q2, &q3, t);
    FUN_0002299c(&d, &a, &b, t);
    FUN_0002299c(&e, &b, &c, t);
    FUN_0002299c(&f, &d, &e, t);
    FUN_00022938(out, &f);
    Mat4 m;
    Vec4 r;
    {
        Vec4 p0 = keys[i].r3;
        Vec4 p1 = keys[i + 1].r3;
        Basis g(p0, p0, p1, p1);
        FUN_00022570(&m, &g, &DAT_002c0f30);
        Vec4 tv(t3, t2, t, 1.0f);
        FUN_00022548(&out->r3, &m, &tv);
    }
    {
        Vec4 s0(keys[i].s.x, keys[i].s.y, keys[i].s.z, 0.0f);
        Vec4 s1(keys[i + 1].s.x, keys[i + 1].s.y, keys[i + 1].s.z, 0.0f);
        Basis g(s0, s0, s1, s1);
        FUN_00022570(&m, &g, &DAT_002c0f30);
        Vec4 tv(t3, t2, t, 1.0f);
        FUN_00022548(&r, &m, &tv);
        out->s.x = r.x;
        out->s.y = r.y;
        out->s.z = r.z;
    }
}
