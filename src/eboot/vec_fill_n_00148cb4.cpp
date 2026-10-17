/* HSTMATCH module=EBOOT.BIN start=0x00148cb4 end=0x00148d5c symbol=FUN_00148cb4 lang=c++ */
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
extern "C" void FUN_00148cb4(Buf *b, Elem *first, Elem *last, False)
{
    Elem *d = b->data + b->start;
    while (first < last) {
        --last;
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), --d);
        if (q)
            FUN_00146b88(q, *last);
        --b->start;
        ++b->size;
    }
}
