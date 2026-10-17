/* HSTMATCH module=EBOOT.BIN start=0x00148d5c end=0x00148e04 symbol=FUN_00148d5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146b88(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00148d5c(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00146b88(q, x);
        ++p;
        ++b->size;
    }
}
