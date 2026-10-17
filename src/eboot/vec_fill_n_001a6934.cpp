/* HSTMATCH module=EBOOT.BIN start=0x001a6934 end=0x001a69c8 symbol=FUN_001a6934 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001a673c(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001a6934(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_001a673c(q, x);
        ++p;
        ++b->size;
    }
}
