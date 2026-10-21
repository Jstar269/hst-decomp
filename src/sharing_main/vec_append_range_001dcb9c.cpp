/* HSTMATCH module=hstp_trans_main.prx start=0x001dcb9c end=0x001dcc30 symbol=FUN_001dcb9c lang=c++ */
/* Clone of src/eboot/vec_append_range_001ce4c0.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152d18(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001dcb9c(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first != last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00152d18(q, *first);
        ++p;
        ++b->size;
    }
}
