/* HSTMATCH module=hstp_trans_main.prx start=0x00154d24 end=0x00154dcc symbol=FUN_00154d24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00154d24 {};
struct Elem_00154d24 { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152704(Elem_00154d24 *, const Elem_00154d24 &);
class Buf_00154d24 {
public:
    Elem_00154d24 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00154d24(Buf_00154d24 *b, unsigned n, const Elem_00154d24 &x, False_00154d24)
{
    Elem_00154d24 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00154d24 *q = (Elem_00154d24 *)FUN_00002f60(sizeof(Elem_00154d24), p);
        if (q)
            FUN_00152704(q, x);
        ++p;
        ++b->size;
    }
}
