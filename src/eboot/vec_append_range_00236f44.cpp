/* HSTMATCH module=EBOOT.BIN start=0x00236f44 end=0x00236fe8 symbol=FUN_00236f44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False {};
struct Elem { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00236890(Elem *, const Elem &);

class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};

extern "C" void FUN_00236f44(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00236890(q, *first);
        ++p;
        ++b->size;
    }
}
