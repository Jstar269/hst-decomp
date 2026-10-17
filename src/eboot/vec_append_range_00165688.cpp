/* HSTMATCH module=EBOOT.BIN start=0x00165688 end=0x00165724 symbol=FUN_00165688 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[0x8b]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001650ec(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00165688(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_001650ec(q, *first);
        ++p;
        ++b->size;
    }
}
