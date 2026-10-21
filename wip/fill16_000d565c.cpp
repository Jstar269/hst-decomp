/* HSTMATCH module=EBOOT.BIN start=0x000d565c end=0x000d5730 symbol=FUN_000d565c lang=c++ */
inline void *operator new(unsigned, void *p) { return p; }
struct Tag_000d565c {};
struct Elem_000d565c {
    int w[4];
    Elem_000d565c(const Elem_000d565c &o) {
        w[0] = o.w[0];
        w[1] = o.w[1];
        w[2] = o.w[2];
        w[3] = o.w[3];
    }
};
class Vec_000d565c;
extern "C" unsigned FUN_000d6450(Vec_000d565c *, unsigned);
extern "C" void FUN_000d61fc(Vec_000d565c *, unsigned, const Elem_000d565c *);
class Vec_000d565c {
public:
    Elem_000d565c *data;
    unsigned size;
    unsigned cap;
    void construct_at_end(unsigned n, const Elem_000d565c &x, Tag_000d565c) {
        Elem_000d565c *p = data + size;
        for (; n != 0; --n) {
            new (p) Elem_000d565c(x);
            ++p;
            ++size;
        }
    }
};
extern "C" void FUN_000d565c(Vec_000d565c *v, unsigned n, const Elem_000d565c *x, Tag_000d565c)
{
    if (n > v->cap || v->size > v->cap - n) {
        FUN_000d6450(v, v->size + n - v->cap);
        FUN_000d61fc(v, n, x);
    } else {
        v->construct_at_end(n, *x, Tag_000d565c());
    }
}
// rt2 2026-10-21: signature confirmed as FUN(Vec*, unsigned n, const Elem *x, Tag) -- the 4th empty Tag
// is needed for retail's frame=32 (with only 3 args MWCC emits frame=16). Source above is the member
// construct_at_end + if/else form: 52/53 words, ALL loop instructions and the grow-call sequence
// word-for-word identical. The only remaining difference is MWCC's block placement of the second call:
// retail emits grow(); b APPEND; loop; APPEND: append(); epilogue, ours emits grow(); append();
// b epilogue; loop; epilogue. Variants: if-body as one inline member grow_append() gives 53/53 words
// with the same permutation (append block before the loop) and reloads v->cap in the grow arg;
// `else { construct; return; } append();` reintroduces a duplicate `lw v1,0(s2)` (+2 words, the known
// 0x000d934c twin near-miss). Element is 4 ints copied memberwise (lw/sw, not lwc1).
// near miss from lane rt2 (unreviewed)
