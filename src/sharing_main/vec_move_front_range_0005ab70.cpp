/* HSTMATCH module=hstp_trans_main.prx start=0x0005ab70 end=0x0005ac18 symbol=FUN_0005ab70 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False_0005ab70 {};
struct Elem_0005ab70 { int w[36]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_0005a484(Elem_0005ab70 *, const Elem_0005ab70 &);
class Buf_0005ab70 {
public:
    Elem_0005ab70 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_0005ab70(Buf_0005ab70 *b, Elem_0005ab70 *first, Elem_0005ab70 *last, False_0005ab70)
{
    Elem_0005ab70 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_0005ab70 *q = (Elem_0005ab70 *)FUN_00002f60(sizeof(Elem_0005ab70), p);
        if (q)
            FUN_0005a484(q, *last);
        --b->start;
        ++b->size;
    }
}
