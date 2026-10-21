/* HSTMATCH module=EBOOT.BIN start=0x0016a234 end=0x0016a364 symbol=FUN_0016a234 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));
struct Mat { float m[16]; } __attribute__((aligned(16)));

extern Mat DAT_002bc410;
extern "C" {
void FUN_0004d278(Mat *, Mat *, float);
void FUN_0004d2cc(Mat *, Mat *, float);
void FUN_00022548(Vec4 *, Mat *, Vec4 *);
float FUN_000224d8(Vec4 *, Vec4 *);
float FUN_00022e44(float);
void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);

void FUN_0016a234(Vec4 *out, float *p2, float *p3, float *p4)
{
    Vec4 c;
    Vec4 a;
    Mat m;
    Vec4 b;
    Vec4 r;
    a = Vec4(0.0f, *p2, 0.0f, 1.0f);
    FUN_0004d278(&m, &DAT_002bc410, *p4);
    FUN_00022548(&a, &m, &a);
    b.x = a.x;
    b.y = 0.0f;
    b.z = a.z;
    b.w = 1.0f;
    float len = FUN_00022e44(FUN_000224d8(&b, &b));
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = len;
    c.w = 1.0f;
    FUN_0004d2cc(&m, &DAT_002bc410, *p3);
    FUN_00022548(&c, &m, &c);
    a = Vec4(0.0f, a.y, 0.0f, 1.0f);
    c = Vec4(c.x, 0.0f, c.z, 1.0f);
    FUN_00022418(&r, &c, &a);
    Vec4 t = r;
    t.w = 1.0f;
    *out = t;
}
}
