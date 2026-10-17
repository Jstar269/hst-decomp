/* HSTMATCH module=hstp_trans_main.prx start=0x00171878 end=0x00171914 symbol=FUN_00171878 lang=c++ */
/* Clone of src/eboot/vec_append_range_00165688.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[0x8b]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001712dc(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00171878(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_001712dc(q, *first);
        ++p;
        ++b->size;
    }
}
