/* HSTMATCH module=hstp_trans_main.prx start=0x00066f5c end=0x00066ff0 symbol=FUN_00066f5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00066ff0(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00066f5c(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first != last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00066ff0(q, *first);
        ++p;
        ++b->size;
    }
}
