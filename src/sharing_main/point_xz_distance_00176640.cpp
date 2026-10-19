/* HSTMATCH module=hstp_trans_main.prx start=0x00176640 end=0x001766cc symbol=FUN_00176640 lang=c++ */
/* Clone of src/eboot/point_xz_distance_0016a47c.cpp (hstclone.py tag s10172123g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}

struct Point {
    float x;
    float y;
    float z;
};

extern "C" float FUN_00176640(const Point *a, const Point *b)
{
    Vec4 d;
    Vec4 p1;
    Vec4 p2;

    float bz = b->z;
    float bx = b->x;
    p2.x = bx;
    p2.z = bz;
    p2.y = 0.0f;
    p2.w = 0.0f;

    float az = a->z;
    float ax = a->x;
    p1.x = ax;
    p1.z = az;
    p1.w = 1.0f;
    p1.y = 0.0f;

    d = Sub(p1, p2);
    return FUN_00022e6c(FUN_00022500(&d, &d));
}
