/* HSTMATCH module=hstp_trans_main.prx start=0x0015424c end=0x001542f4 symbol=FUN_0015424c lang=c++ */
/* Clone of src/eboot/vec_fill_n_000b52f4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements: append n copies of x after the current contents (placement new 0x2f60 +
   copy constructor 0xb43e8); same shape as src/eboot/vec_fill_n_00148cb4.cpp. Names provisional. */
struct False_0015424c {};
struct Elem_0015424c { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152324(Elem_0015424c *, const Elem_0015424c &);
class Buf_0015424c {
public:
    Elem_0015424c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_0015424c(Buf_0015424c *b, unsigned n, const Elem_0015424c &x, False_0015424c)
{
    Elem_0015424c *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_0015424c *q = (Elem_0015424c *)FUN_00002f60(sizeof(Elem_0015424c), p);
        if (q)
            FUN_00152324(q, x);
        ++p;
        ++b->size;
    }
}
