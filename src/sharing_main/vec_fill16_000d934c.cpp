/* HSTMATCH module=hstp_trans_main.prx start=0x000d934c end=0x000d9420 symbol=FUN_000d934c lang=c++ */
/* Clone of src/eboot/vec_fill16_000d565c.cpp (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the out-of-line append call is sunk below the else block and the else path reaches it through a goto that skips it; names and types await human review. */
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
extern "C" unsigned FUN_000da140(Vec_000d934c *, unsigned);
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
extern "C" void FUN_000d934c(Vec_000d934c *v, unsigned n, const Elem_000d934c *x, Tag_000d934c)
{
    if (n > v->cap || v->size > v->cap - n) {
        FUN_000da140(v, v->size + n - v->cap);
    } else {
        v->construct_at_end(n, *x, Tag_000d934c());
        goto done;
    }
    FUN_000d9eec(v, n, x);
done:;
}
