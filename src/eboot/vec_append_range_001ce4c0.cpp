/* HSTMATCH module=EBOOT.BIN start=0x001ce4c0 end=0x001ce554 symbol=FUN_001ce4c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00147430(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001ce4c0(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first != last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00147430(q, *first);
        ++p;
        ++b->size;
    }
}
