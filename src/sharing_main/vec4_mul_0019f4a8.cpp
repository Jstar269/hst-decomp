/* HSTMATCH module=hstp_trans_main.prx start=0x0019f4a8 end=0x0019f4f0 symbol=FUN_0019f4a8 lang=c++ */
/* Clone of src/eboot/vec4_mul_000542a0.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" Vec4 *FUN_00022478(Vec4 *, const Vec4 *, const Vec4 *);

extern "C" Vec4 FUN_0019f4a8(const Vec4 *a, const Vec4 *b)
{
    Vec4 r;
    FUN_00022478(&r, a, b);
    return r;
}
