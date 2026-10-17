/* HSTMATCH module=EBOOT.BIN start=0x00165c30 end=0x00165cd8 symbol=FUN_00165c30 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00165c30 {};
struct Elem_00165c30 { int w[139]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001650ec(Elem_00165c30 *, const Elem_00165c30 &);
class Buf_00165c30 {
public:
    Elem_00165c30 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00165c30(Buf_00165c30 *b, Elem_00165c30 *first, Elem_00165c30 *last, False_00165c30)
{
    Elem_00165c30 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_00165c30 *q = (Elem_00165c30 *)FUN_00002f60(sizeof(Elem_00165c30), p);
        if (q)
            FUN_001650ec(q, *last);
        --b->start;
        ++b->size;
    }
}
