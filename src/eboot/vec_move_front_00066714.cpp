/* HSTMATCH module=EBOOT.BIN start=0x00066714 end=0x000667bc symbol=FUN_00066714 lang=c++ */
/* Clone of src/eboot/vec_move_front_00148d5c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_00066714(Buf *b, unsigned n, const Elem &x, False)
{
    Elem *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00065b9c(q, x);
        ++p;
        ++b->size;
    }
}
