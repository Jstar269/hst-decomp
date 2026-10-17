/* HSTMATCH module=hstp_trans_main.prx start=0x0015587c end=0x00155924 symbol=FUN_0015587c lang=c++ */
/* Clone of src/eboot/vec_fill_n_000b52f4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements: append n copies of x after the current contents (placement new 0x2f60 +
   copy constructor 0xb43e8); same shape as src/eboot/vec_fill_n_00148cb4.cpp. Names provisional. */
struct False_0015587c {};
struct Elem_0015587c { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152d18(Elem_0015587c *, const Elem_0015587c &);
class Buf_0015587c {
public:
    Elem_0015587c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_0015587c(Buf_0015587c *b, unsigned n, const Elem_0015587c &x, False_0015587c)
{
    Elem_0015587c *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_0015587c *q = (Elem_0015587c *)FUN_00002f60(sizeof(Elem_0015587c), p);
        if (q)
            FUN_00152d18(q, x);
        ++p;
        ++b->size;
    }
}
