/* HSTMATCH module=EBOOT.BIN start=0x00237770 end=0x00237828 symbol=FUN_00237770 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00237770 {};
struct Elem_00237770 { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00236890(Elem_00237770 *, const Elem_00237770 &);
class Buf_00237770 {
public:
    Elem_00237770 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00237770(Buf_00237770 *b, unsigned n, const Elem_00237770 &x, False_00237770)
{
    Elem_00237770 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00237770 *q = (Elem_00237770 *)FUN_00002f60(sizeof(Elem_00237770), p);
        if (q)
            FUN_00236890(q, x);
        ++p;
        ++b->size;
    }
}
