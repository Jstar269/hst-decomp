/* HSTMATCH module=EBOOT.BIN start=0x0016a47c end=0x0016a508 symbol=FUN_0016a47c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

struct Point {
    float x;
    float y;
    float z;
};

extern "C" float FUN_0016a47c(const Point *a, const Point *b)
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
    return FUN_00022e44(FUN_000224d8(&d, &d));
}
