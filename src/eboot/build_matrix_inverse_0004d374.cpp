/* HSTMATCH module=EBOOT.BIN start=0x0004d374 end=0x0004d414 symbol=FUN_0004d374 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4
{
    float x, y, z, w;
};

struct Mat4
{
    Vec4 r0, r1, r2, r3;
};

extern "C" Vec4 *FUN_000224f8(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern "C" Vec4 *FUN_00022518(Vec4 *out, const Vec4 *a);
extern "C" void FUN_0002c8dc(Mat4 *out, const Mat4 *a);

extern "C" void FUN_0004d374(Mat4 *out, const Vec4 *src, const Vec4 *a3, const Vec4 *a4)
{
    Mat4 m;
    Vec4 t;

    FUN_000224f8(&t, a4, a3);
    FUN_00022518(&m.r0, &t);
    m.r0.w = 0.0f;
    FUN_00022518(&m.r2, a3);
    m.r2.w = 0.0f;
    FUN_000224f8(&m.r1, &m.r2, &m.r0);
    m.r3 = *src;
    FUN_0002c8dc(out, &m);
}
