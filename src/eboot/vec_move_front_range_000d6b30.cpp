/* HSTMATCH module=EBOOT.BIN start=0x000d6b30 end=0x000d6bd8 symbol=FUN_000d6b30 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_000d6b30 {};
struct Elem_000d6b30 { int w[6]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000d5948(Elem_000d6b30 *, const Elem_000d6b30 &);
class Buf_000d6b30 {
public:
    Elem_000d6b30 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000d6b30(Buf_000d6b30 *b, Elem_000d6b30 *first, Elem_000d6b30 *last, False_000d6b30)
{
    Elem_000d6b30 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_000d6b30 *q = (Elem_000d6b30 *)FUN_00002f60(sizeof(Elem_000d6b30), p);
        if (q)
            FUN_000d5948(q, *last);
        --b->start;
        ++b->size;
    }
}
