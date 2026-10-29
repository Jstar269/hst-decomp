/* HSTMATCH module=EBOOT.BIN start=0x000e8468 end=0x000e855c symbol=FUN_000e8468 lang=c++ */
struct Elem8 { float f[8]; };
struct False_000e8468 {};
struct Alloc_000e8468 {
    void construct(Elem8 *p, const Elem8 &x) { if (p) { for (int i = 0; i < 8; ++i) p->f[i] = x.f[i]; } }
};
struct Vec_000e8468 {
    Elem8 *data;
    unsigned size;
    unsigned capacity;
    void construct_at_end(unsigned n, const Elem8 &x, False_000e8468) {
        Elem8 *p = data + size;
        for (; n != 0; --n) {
            Alloc_000e8468().construct(p, x);
            ++p;
            ++size;
        }
    }
};
extern "C" unsigned FUN_000e8be0(Vec_000e8468 *v, unsigned need);
extern "C" void FUN_000e894c(Vec_000e8468 *v, unsigned n, const Elem8 &x);
extern "C" void FUN_000e8468(Vec_000e8468 *v, unsigned n, const Elem8 &x)
{
    if (n > v->capacity || v->size > v->capacity - n) {
        FUN_000e8be0(v, v->size + n - v->capacity);
    } else {
        v->construct_at_end(n, x, False_000e8468());
        return;
    }
    FUN_000e894c(v, n, x);
}
// near miss from lane dsn3 (unreviewed)
