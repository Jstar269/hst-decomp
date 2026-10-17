/* HSTMATCH module=hstp_trans_main.prx start=0x000d934c end=0x000d9420 symbol=FUN_000d934c lang=c++ */

inline void *operator new(unsigned, void *p) { return p; }
struct Tag_000d934c {};
struct Elem_000d934c {
    int w[4];
    Elem_000d934c(const Elem_000d934c &o) {
        w[0] = o.w[0];
        w[1] = o.w[1];
        w[2] = o.w[2];
        w[3] = o.w[3];
    }
};

class Vec_000d934c;
extern "C" void FUN_000da140(Vec_000d934c *, unsigned);
extern "C" void FUN_000d9eec(Vec_000d934c *, unsigned, const Elem_000d934c *);

class Vec_000d934c {
public:
    Elem_000d934c *data;
    unsigned size;
    unsigned cap;

    void construct_at_end(unsigned n, const Elem_000d934c &x, Tag_000d934c) {
        Elem_000d934c *p = data + size;
        for (; n != 0; --n) {
            new (p) Elem_000d934c(x);
            ++p;
            ++size;
        }
    }
};

extern "C" void FUN_000d934c(Vec_000d934c *v, unsigned n, const Elem_000d934c *x)
{
    if (n > v->cap || v->size > v->cap - n) {
        FUN_000da140(v, v->size + n - v->cap);
    } else {
        v->construct_at_end(n, *x, Tag_000d934c());
        return;
    }
    FUN_000d9eec(v, n, x);
}

// NEAR MISS: 55 vs 53 words (+2 words, diff starting at +0x38).
// Twin of 0x000ed8e4 (integer element version of vector fill append).
// In retail, the fast-path entry hoists `lw v1, 0(s2)` into the delay slot of `beqzl at, 0xd93a8`
// and branches directly to `0xd93a8: sll a0, a0, 0x4`.
// Under MWCC -O4,p, the compiler duplicates `lw v1, 0(s2)` at 0xd93a8 before `sll a0, a0, 0x4`,
// and jumps to 0xd93ac, adding 2 words (+0x8 bytes offset shift for all following code).
// All loop instructions (lw/sw quad unrolling, aliasing size reload, delay slots) match retail.
// near miss from lane u1r2-3 (unreviewed)
