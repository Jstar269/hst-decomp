/* HSTMATCH module=EBOOT.BIN start=0x00169f24 end=0x0016a000 symbol=FUN_00169f24 lang=c++ */
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
    float dy = p2->y - p1->y;
    if (dy == 0.0f)
        return 1.5707964f;
    return FUN_0000c6dc(len, dy);
}

// NEAR MISS: 3 of 55 words differ (all in the tail): retail loads p1->y into $f3 BEFORE
// p2->y into $f2 and then does `sub.s $f13,$f2,$f3`; this source gets the same values with the
// two loads swapped and `sub.s $f13,$f3,$f2`. Instruction stream is otherwise identical, so a
// register permutation of $f2/$f3 solves it. Tried (all 3 off): dy computed before len; `dy = p2->y;
// dy -= p1->y;`; explicit y1/y2 locals; -(p1->y - p2->y); reversed parameter order; inline GetY()
// helpers; different struct views for the rhs; `if (p2->y == p1->y)` + inline difference.
// near miss from lane ds7 (unreviewed)
