/* HSTMATCH module=hstp_trans_main.prx start=0x000ec4e0 end=0x000ec5f0 symbol=FUN_000ec4e0 lang=c++ */
/* Clone of src/eboot/mat4_init_rows_000e74e4.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000ec4e0 { float x, y, z, w; };
struct Mat4_000ec4e0 { Vec4_000ec4e0 r0, r1, r2, r3; };
static inline void Init_000ec4e0(Mat4_000ec4e0 *m, Vec4_000ec4e0 a, Vec4_000ec4e0 b,
                                 Vec4_000ec4e0 c, Vec4_000ec4e0 d)
{
    m->r0 = a;
    m->r1 = b;
    m->r2 = c;
    m->r3 = d;
}
extern "C" float *FUN_000ec4e0(float *out, const Vec4_000ec4e0 *a, const Vec4_000ec4e0 *b,
                               const Vec4_000ec4e0 *c, const Vec4_000ec4e0 *d)
{
    Init_000ec4e0((Mat4_000ec4e0 *)out, *a, *b, *c, *d);
    return out;
}
