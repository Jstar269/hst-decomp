/* HSTMATCH module=EBOOT.BIN start=0x000e8810 end=0x000e88e4 symbol=FUN_000e8810 lang=c++ */

inline void *operator new(unsigned, void *p) { return p; }
struct Tag_000ed8e4 {};
struct Elem_000ed8e4 {
    float x, y, z, w;
    Elem_000ed8e4(const Elem_000ed8e4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};
struct Vec_000ed8e4 {
    Elem_000ed8e4 *data;
    unsigned size;
    unsigned cap;
};

extern "C" void FUN_000e92c8(Vec_000ed8e4 *, unsigned);
extern "C" void FUN_000e9074(Vec_000ed8e4 *, unsigned, const Elem_000ed8e4 *);

inline void Fill(Elem_000ed8e4 *p, unsigned m, const Elem_000ed8e4 *x, Vec_000ed8e4 *v, Tag_000ed8e4)
{
    for (; m != 0; --m) {
        if (p) {
            p->x = x->x;
            p->y = x->y;
            p->z = x->z;
            p->w = x->w;
        }
        ++p;
        ++v->size;
    }
}

extern "C" void FUN_000e8810(Vec_000ed8e4 *v, unsigned n, const Elem_000ed8e4 *x)
{
    if (n <= v->cap) {
        if (v->size <= v->cap - n) {
            Fill(v->data + v->size, n, x, v, Tag_000ed8e4());
            return;
        }
    }
    {
        FUN_000e92c8(v, (v->size + n) - v->cap);
        FUN_000e9074(v, n, x);
    }
}

// NEAR MISS: 31 differing words out of 53 after 15 compile attempts.
// EBOOT helper references are retargeted to FUN_000e92c8 and FUN_000e9074.
// The original combined guard matched the Sharing twin's two-word schedule miss
// but left 34 differing words on EBOOT. Nested capacity guards reduce that to 31,
// though the slow/grow and fast/fill block layout now diverges starting at +0x24.
// Tested direct loop expansion, an early-return grow path, a local data pointer,
// begin() accessor, inline NeedsGrow helper, staged bool guards, reordered Fill
// parameters, a member Fill method, and a local Tag; none improved 31 differences.
// Remaining investigation: align the branch target and data-pointer load in the
// second capacity check without shifting the fast loop.
// near miss from lane lnm2 (unreviewed)
