/* HSTMATCH module=EBOOT.BIN start=0x000d57a8 end=0x000d589c symbol=FUN_000d57a8 lang=c++ */
inline void *operator new(unsigned, void *p) { return p; }
struct Elem8 { int w[8]; };
struct False_000d57a8 {};
struct Alloc_000d57a8 {
    void construct(Elem8 *p, const Elem8 &x) { new (p) Elem8(x); }
};
struct Vec_000d57a8 {
    Elem8 *data;
    unsigned size;
    unsigned capacity;
    void construct_at_end(unsigned n, const Elem8 &x, False_000d57a8) {
        Elem8 *p = data + size;
        for (; n != 0; --n) {
            Alloc_000d57a8().construct(p, x);
            ++p;
            ++size;
        }
    }
};
extern "C" unsigned FUN_000d67c8(Vec_000d57a8 *v, unsigned need);
extern "C" void FUN_000d6534(Vec_000d57a8 *v, unsigned n, const Elem8 &x);
extern "C" void FUN_000d57a8(Vec_000d57a8 *v, unsigned n, const Elem8 &x)
{
    if (n > v->capacity || v->size > v->capacity - n) {
        FUN_000d67c8(v, v->size + n - v->capacity);
        FUN_000d6534(v, n, x);
        return;
    }
    v->construct_at_end(n, x, False_000d57a8());
}
// near miss from lane dsn3 (unreviewed)
