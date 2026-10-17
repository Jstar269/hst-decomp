/* HSTMATCH module=hstp_trans_main.prx start=0x000ed8e4 end=0x000ed9b8 symbol=FUN_000ed8e4 lang=c++ */

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

extern "C" void FUN_000ee39c(Vec_000ed8e4 *, unsigned);
extern "C" void FUN_000ee148(Vec_000ed8e4 *, unsigned, const Elem_000ed8e4 *);

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

extern "C" void FUN_000ed8e4(Vec_000ed8e4 *v, unsigned n, const Elem_000ed8e4 *x)
{
    if (n > v->cap || v->size > v->cap - n) {
        FUN_000ee39c(v, (v->size + n) - v->cap);
    } else {
        Fill(v->data + v->size, n, x, v, Tag_000ed8e4());
        return;
    }
    FUN_000ee148(v, n, x);
}

// NEAR MISS: 55 vs 53 words (+2 words, diff starting at +0x38).
// In retail, the fast-path entry hoists `lw v1, 0(s2)` into the delay slot of `beqzl at, 0xed940`
// and branches directly to `0xed940: sll a0, a0, 0x4`.
// Under MWCC -O4,p, the compiler duplicates `lw v1, 0(s2)` at 0xed940 before `sll a0, a0, 0x4`,
// and jumps to 0xed944, adding 2 words (+0x8 bytes offset shift for all following code).
// All loop instructions (lwc1/swc1 quad unrolling, aliasing size reload, delay slots) match retail.
// near miss from lane u1r2-3 (unreviewed)
