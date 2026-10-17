/* HSTMATCH module=EBOOT.BIN start=0x00148964 end=0x00148a0c symbol=FUN_00148964 lang=c++ */
/* Clone of src/eboot/vec_fill_n_000b52f4.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements: append n copies of x after the current contents (placement new 0x2f60 +
   copy constructor 0xb43e8); same shape as src/eboot/vec_fill_n_00148cb4.cpp. Names provisional. */
struct False_00148964 {};
struct Elem_00148964 { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146a3c(Elem_00148964 *, const Elem_00148964 &);
class Buf_00148964 {
public:
    Elem_00148964 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00148964(Buf_00148964 *b, unsigned n, const Elem_00148964 &x, False_00148964)
{
    Elem_00148964 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00148964 *q = (Elem_00148964 *)FUN_00002f60(sizeof(Elem_00148964), p);
        if (q)
            FUN_00146a3c(q, x);
        ++p;
        ++b->size;
    }
}
