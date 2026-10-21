/* HSTMATCH module=EBOOT.BIN start=0x000e74e4 end=0x000e75f4 symbol=FUN_000e74e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000e74e4 { float x, y, z, w; };
struct Mat4_000e74e4 { Vec4_000e74e4 r0, r1, r2, r3; };
static inline void Init_000e74e4(Mat4_000e74e4 *m, Vec4_000e74e4 a, Vec4_000e74e4 b,
                                 Vec4_000e74e4 c, Vec4_000e74e4 d)
{
    m->r0 = a;
    m->r1 = b;
    m->r2 = c;
    m->r3 = d;
}
extern "C" float *FUN_000e74e4(float *out, const Vec4_000e74e4 *a, const Vec4_000e74e4 *b,
                               const Vec4_000e74e4 *c, const Vec4_000e74e4 *d)
{
    Init_000e74e4((Mat4_000e74e4 *)out, *a, *b, *c, *d);
    return out;
}
