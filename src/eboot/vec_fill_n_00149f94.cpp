/* HSTMATCH module=EBOOT.BIN start=0x00149f94 end=0x0014a03c symbol=FUN_00149f94 lang=c++ */
/* Clone of src/eboot/vec_fill_n_000b52f4.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements: append n copies of x after the current contents (placement new 0x2f60 +
   copy constructor 0xb43e8); same shape as src/eboot/vec_fill_n_00148cb4.cpp. Names provisional. */
struct False_00149f94 {};
struct Elem_00149f94 { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00147430(Elem_00149f94 *, const Elem_00149f94 &);
class Buf_00149f94 {
public:
    Elem_00149f94 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00149f94(Buf_00149f94 *b, unsigned n, const Elem_00149f94 &x, False_00149f94)
{
    Elem_00149f94 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00149f94 *q = (Elem_00149f94 *)FUN_00002f60(sizeof(Elem_00149f94), p);
        if (q)
            FUN_00147430(q, x);
        ++p;
        ++b->size;
    }
}
