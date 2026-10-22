/* HSTMATCH module=EBOOT.BIN start=0x000d565c end=0x000d5730 symbol=FUN_000d565c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the out-of-line append call is sunk below the else block and the else path reaches it through a goto that skips it; names and types await human review. */
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
    } else {
        v->construct_at_end(n, *x, Tag_000d565c());
        goto done;
    }
    FUN_000d61fc(v, n, x);
done:;
}
