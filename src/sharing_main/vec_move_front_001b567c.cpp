/* HSTMATCH module=hstp_trans_main.prx start=0x001b567c end=0x001b5724 symbol=FUN_001b567c lang=c++ */
/* Clone of src/eboot/vec_move_front_00066714.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_001b567c(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_001b3d08(q, x);
        ++p;
        ++b->size;
    }
}
