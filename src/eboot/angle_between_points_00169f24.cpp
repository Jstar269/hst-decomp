/* HSTMATCH module=EBOOT.BIN start=0x00169f24 end=0x0016a000 symbol=FUN_00169f24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: dy is first loaded from p1->y and then overwritten by p2->y - dy, which fixes the load order and the f2/f3 numbering); names and types await human review. */
struct Vec4 { float x, y, z, w; Vec4() {} Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
extern "C" void FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
extern "C" float FUN_000224d8(Vec4 *, Vec4 *);
extern "C" float FUN_00022e44(float);
extern "C" float FUN_0000c6dc(float, float);
static inline Vec4 operator-(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022434(&r, &a, &b); return r; }
extern "C" float FUN_00169f24(Vec4 *p1, Vec4 *p2) {
    Vec4 d;
    Vec4 b;
    Vec4 a;
    a = Vec4(p1->x, 0.0f, p1->z, 0.0f);
    b = Vec4(p2->x, 0.0f, p2->z, 1.0f);
    d = b - a;
    float len = FUN_00022e44(FUN_000224d8(&d, &d));
    float dy = p1->y;
    dy = p2->y - dy;
    if (dy == 0.0f)
        return 1.5707964f;
    return FUN_0000c6dc(len, dy);
}
