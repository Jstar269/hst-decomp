/* HSTMATCH module=EBOOT.BIN start=0x0006666c end=0x00066714 symbol=FUN_0006666c lang=c++ */
/* Clone of src/eboot/vec_fill_n_00148cb4.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00065b9c(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_0006666c(Buf *b, Elem *first, Elem *last, False)
{
    Elem *d = b->data + b->start;
    while (first < last) {
        --last;
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), --d);
        if (q)
            FUN_00065b9c(q, *last);
        --b->start;
        ++b->size;
    }
}
