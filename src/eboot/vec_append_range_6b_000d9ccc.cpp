/* HSTMATCH module=EBOOT.BIN start=0x000d9ccc end=0x000d9d84 symbol=FUN_000d9ccc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v1) corrected by hand: forward range append of 6-byte elements (copy ctor, inline placement new, unused empty tag parameter and tag temporary for FUN_000da72c as in the 0x165688 helpers); exact match verified; names and types await human review. */
struct False {};
struct Elem_000d9ccc {
    short a, b, c;
    Elem_000d9ccc(const Elem_000d9ccc &o) : a(o.a), b(o.b), c(o.c) {}
};
struct Buf_000d9ccc {
    Elem_000d9ccc *data;
    int size;
};
inline void *operator new(unsigned, void *p) { return p; }
extern "C" void FUN_000da72c(Buf_000d9ccc *, int, False);

extern "C" void FUN_000d9ccc(Buf_000d9ccc *b, Elem_000d9ccc *first, Elem_000d9ccc *last, False)
{
    int n = last - first;
    if (n != 0) {
        FUN_000da72c(b, n, False());
        Elem_000d9ccc *p = b->data + b->size;
        for (; first != last; ++first) {
            new (p) Elem_000d9ccc(*first);
            ++p;
            ++b->size;
        }
    }
}
