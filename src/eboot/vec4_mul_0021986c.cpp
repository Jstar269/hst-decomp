/* HSTMATCH module=EBOOT.BIN start=0x0021986c end=0x002198b4 symbol=FUN_0021986c lang=c++ */
/* Clone of src/eboot/vec4_mul_00192c98.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);

extern "C" Vec4 FUN_0021986c(const Vec4 *a, const Vec4 *b)
{
    Vec4 r;
    FUN_00022418(&r, a, b);
    return r;
}
