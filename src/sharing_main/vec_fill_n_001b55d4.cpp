/* HSTMATCH module=hstp_trans_main.prx start=0x001b55d4 end=0x001b567c symbol=FUN_001b55d4 lang=c++ */
/* Clone of src/eboot/vec_fill_n_0006666c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001b3d08(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001b55d4(Buf *b, Elem *first, Elem *last, False)
{
    Elem *d = b->data + b->start;
    while (first < last) {
        --last;
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), --d);
        if (q)
            FUN_001b3d08(q, *last);
        --b->start;
        ++b->size;
    }
}
