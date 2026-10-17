/* HSTMATCH module=hstp_trans_main.prx start=0x000da8c8 end=0x000da970 symbol=FUN_000da8c8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_000da8c8 {};
struct Elem_000da8c8 { int w[6]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000d9638(Elem_000da8c8 *, const Elem_000da8c8 &);
class Buf_000da8c8 {
public:
    Elem_000da8c8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000da8c8(Buf_000da8c8 *b, unsigned n, const Elem_000da8c8 &x, False_000da8c8)
{
    Elem_000da8c8 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_000da8c8 *q = (Elem_000da8c8 *)FUN_00002f60(sizeof(Elem_000da8c8), p);
        if (q)
            FUN_000d9638(q, x);
        ++p;
        ++b->size;
    }
}
