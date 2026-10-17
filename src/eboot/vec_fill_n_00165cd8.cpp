/* HSTMATCH module=EBOOT.BIN start=0x00165cd8 end=0x00165d7c symbol=FUN_00165cd8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00165cd8 {};
struct Elem_00165cd8 { int w[139]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001650ec(Elem_00165cd8 *, const Elem_00165cd8 &);
class Buf_00165cd8 {
public:
    Elem_00165cd8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00165cd8(Buf_00165cd8 *b, unsigned n, const Elem_00165cd8 &x, False_00165cd8)
{
    Elem_00165cd8 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00165cd8 *q = (Elem_00165cd8 *)FUN_00002f60(sizeof(Elem_00165cd8), p);
        if (q)
            FUN_001650ec(q, x);
        ++p;
        ++b->size;
    }
}
