/* HSTMATCH module=hstp_trans_main.prx start=0x00171ec8 end=0x00171f6c symbol=FUN_00171ec8 lang=c++ */
/* Clone of src/eboot/vec_fill_n_00165cd8.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00171ec8 {};
struct Elem_00171ec8 { int w[139]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001712dc(Elem_00171ec8 *, const Elem_00171ec8 &);
class Buf_00171ec8 {
public:
    Elem_00171ec8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00171ec8(Buf_00171ec8 *b, unsigned n, const Elem_00171ec8 &x, False_00171ec8)
{
    Elem_00171ec8 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_00171ec8 *q = (Elem_00171ec8 *)FUN_00002f60(sizeof(Elem_00171ec8), p);
        if (q)
            FUN_001712dc(q, x);
        ++p;
        ++b->size;
    }
}
