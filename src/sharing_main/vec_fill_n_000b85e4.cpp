/* HSTMATCH module=hstp_trans_main.prx start=0x000b85e4 end=0x000b868c symbol=FUN_000b85e4 lang=c++ */
/* Clone of src/eboot/vec_fill_n_000b52f4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements: append n copies of x after the current contents (placement new 0x2f60 +
   copy constructor 0xb43e8); same shape as src/eboot/vec_fill_n_00148cb4.cpp. Names provisional. */
struct False_000b85e4 {};
struct Elem_000b85e4 { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000b76d8(Elem_000b85e4 *, const Elem_000b85e4 &);
class Buf_000b85e4 {
public:
    Elem_000b85e4 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000b85e4(Buf_000b85e4 *b, unsigned n, const Elem_000b85e4 &x, False_000b85e4)
{
    Elem_000b85e4 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_000b85e4 *q = (Elem_000b85e4 *)FUN_00002f60(sizeof(Elem_000b85e4), p);
        if (q)
            FUN_000b76d8(q, x);
        ++p;
        ++b->size;
    }
}
