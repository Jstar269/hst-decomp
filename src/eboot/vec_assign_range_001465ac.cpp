/* HSTMATCH module=EBOOT.BIN start=0x001465ac end=0x00146654 symbol=FUN_001465ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: assign(first, last) from a pointer range (3-arg variant of 0x179fb0 with out-of-line grow 0x14a6d8 and reserve 0x14a7bc); the empty tag temporary of the inline copy gives the extra 16 bytes of frame. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_001465ac {};
typedef void *Elem_001465ac;
struct Vec_001465ac { Elem_001465ac *data; int size; unsigned capacity; };
extern "C" unsigned FUN_0014a6d8(Vec_001465ac *v, unsigned n);
extern "C" void FUN_0014a7bc(Vec_001465ac *v, unsigned n, unsigned cap);
inline void Copy_001465ac(Elem_001465ac *d, Elem_001465ac *f, Elem_001465ac *l, Tag_001465ac)
{
    FUN_000111c0(d, f, (l - f) * sizeof(Elem_001465ac));
}
extern "C" void FUN_001465ac(Vec_001465ac *v, Elem_001465ac *first, Elem_001465ac *last)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_001465ac);
    if (n > v->capacity)
        FUN_0014a7bc(v, n, FUN_0014a6d8(v, n - v->capacity));
    Copy_001465ac(v->data, first, last, Tag_001465ac());
    v->size = n;
}
