/* HSTMATCH module=hstp_trans_main.prx start=0x00154960 end=0x00154a10 symbol=FUN_00154960 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00154960 {};
struct Elem_00154960 { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152704(Elem_00154960 *, const Elem_00154960 &);
class Buf_00154960 {
public:
    Elem_00154960 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00154960(Buf_00154960 *b, Elem_00154960 *first, Elem_00154960 *last, False_00154960)
{
    Elem_00154960 *p = b->data + b->start + b->size;
    for (; first < last; ++first) {
        Elem_00154960 *q = (Elem_00154960 *)FUN_00002f60(sizeof(Elem_00154960), p);
        if (q)
            FUN_00152704(q, *first);
        ++p;
        ++b->size;
    }
}
