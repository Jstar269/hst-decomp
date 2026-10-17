/* HSTMATCH module=hstp_trans_main.prx start=0x00067358 end=0x000673f4 symbol=FUN_00067358 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False_00067358 {};
struct Elem_00067358 { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00066ff0(Elem_00067358 *, const Elem_00067358 &);
class Buf_00067358 {
public:
    Elem_00067358 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00067358(Buf_00067358 *b, Elem_00067358 *first, Elem_00067358 *last, False_00067358)
{
    Elem_00067358 *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem_00067358 *q = (Elem_00067358 *)FUN_00002f60(sizeof(Elem_00067358), p);
        if (q)
            FUN_00066ff0(q, *first);
        ++p;
        ++b->size;
    }
}
