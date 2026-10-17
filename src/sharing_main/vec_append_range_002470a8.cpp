/* HSTMATCH module=hstp_trans_main.prx start=0x002470a8 end=0x0024714c symbol=FUN_002470a8 lang=c++ */
/* Clone of src/eboot/vec_append_range_00236f44.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False {};
struct Elem { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_002469f4(Elem *, const Elem &);

class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};

extern "C" void FUN_002470a8(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_002469f4(q, *first);
        ++p;
        ++b->size;
    }
}
