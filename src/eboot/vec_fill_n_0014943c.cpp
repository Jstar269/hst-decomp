/* HSTMATCH module=EBOOT.BIN start=0x0014943c end=0x001494e4 symbol=FUN_0014943c lang=c++ */
/* Clone of src/sharing_main/vec_fill_n_00154d24.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_0014943c {};
struct Elem_0014943c { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146e1c(Elem_0014943c *, const Elem_0014943c &);
class Buf_0014943c {
public:
    Elem_0014943c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_0014943c(Buf_0014943c *b, unsigned n, const Elem_0014943c &x, False_0014943c)
{
    Elem_0014943c *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_0014943c *q = (Elem_0014943c *)FUN_00002f60(sizeof(Elem_0014943c), p);
        if (q)
            FUN_00146e1c(q, x);
        ++p;
        ++b->size;
    }
}
