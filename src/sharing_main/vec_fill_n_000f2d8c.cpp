/* HSTMATCH module=hstp_trans_main.prx start=0x000f2d8c end=0x000f2e20 symbol=FUN_000f2d8c lang=c++ */
/* Clone of src/eboot/vec_fill_n_000ed6c4.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[24]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000f2e20(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000f2d8c(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_000f2e20(q, x);
        ++p;
        ++b->size;
    }
}
