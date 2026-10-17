/* HSTMATCH module=EBOOT.BIN start=0x000ed6c4 end=0x000ed758 symbol=FUN_000ed6c4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[24]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000ed758(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000ed6c4(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_000ed758(q, x);
        ++p;
        ++b->size;
    }
}
