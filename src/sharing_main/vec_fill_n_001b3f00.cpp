/* HSTMATCH module=hstp_trans_main.prx start=0x001b3f00 end=0x001b3f94 symbol=FUN_001b3f00 lang=c++ */
/* Clone of src/eboot/vec_fill_n_001a6934.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_001b3f00(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_001b3d08(q, x);
        ++p;
        ++b->size;
    }
}
