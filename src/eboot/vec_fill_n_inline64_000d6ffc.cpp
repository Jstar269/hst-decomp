/* HSTMATCH module=EBOOT.BIN start=0x000d6ffc end=0x000d70c4 symbol=FUN_000d6ffc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 64-byte elements: append n copies of x after the current contents (inlined placement new + memberwise float copy). Names provisional. */
struct Elem { float f[16]; };
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000d6ffc(Buf *b, unsigned n, const Elem *x)
{
    Elem *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        if (p) {
            p->f[0] = x->f[0];
            p->f[1] = x->f[1];
            p->f[2] = x->f[2];
            p->f[3] = x->f[3];
            p->f[4] = x->f[4];
            p->f[5] = x->f[5];
            p->f[6] = x->f[6];
            p->f[7] = x->f[7];
            p->f[8] = x->f[8];
            p->f[9] = x->f[9];
            p->f[10] = x->f[10];
            p->f[11] = x->f[11];
            p->f[12] = x->f[12];
            p->f[13] = x->f[13];
            p->f[14] = x->f[14];
            p->f[15] = x->f[15];
        }
        ++p;
        ++b->size;
    }
}
