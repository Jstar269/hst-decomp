/* HSTMATCH module=EBOOT.BIN start=0x002376c0 end=0x00237770 symbol=FUN_002376c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_002376c0 {};
struct Elem_002376c0 { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00236890(Elem_002376c0 *, const Elem_002376c0 &);
class Buf_002376c0 {
public:
    Elem_002376c0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_002376c0(Buf_002376c0 *b, Elem_002376c0 *first, Elem_002376c0 *last, False_002376c0)
{
    Elem_002376c0 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_002376c0 *q = (Elem_002376c0 *)FUN_00002f60(sizeof(Elem_002376c0), p);
        if (q)
            FUN_00236890(q, *last);
        --b->start;
        ++b->size;
    }
}
