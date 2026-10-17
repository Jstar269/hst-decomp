/* HSTMATCH module=EBOOT.BIN start=0x00192c98 end=0x00192ce0 symbol=FUN_00192c98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);

extern "C" Vec4 FUN_00192c98(const Vec4 *a, const Vec4 *b)
{
    Vec4 r;
    FUN_00022450(&r, a, b);
    return r;
}
