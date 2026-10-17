/* HSTMATCH module=EBOOT.BIN start=0x00148fd0 end=0x00149078 symbol=FUN_00148fd0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00148fd0 {};
struct Elem_00148fd0 { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146e1c(Elem_00148fd0 *, const Elem_00148fd0 &);
class Buf_00148fd0 {
public:
    Elem_00148fd0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00148fd0(Buf_00148fd0 *b, Elem_00148fd0 *first, Elem_00148fd0 *last, False_00148fd0)
{
    Elem_00148fd0 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_00148fd0 *q = (Elem_00148fd0 *)FUN_00002f60(sizeof(Elem_00148fd0), p);
        if (q)
            FUN_00146e1c(q, *last);
        --b->start;
        ++b->size;
    }
}
