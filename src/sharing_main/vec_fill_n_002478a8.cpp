/* HSTMATCH module=hstp_trans_main.prx start=0x002478a8 end=0x00247960 symbol=FUN_002478a8 lang=c++ */
/* Clone of src/eboot/vec_fill_n_00237770.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_002478a8 {};
struct Elem_002478a8 { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_002469f4(Elem_002478a8 *, const Elem_002478a8 &);
class Buf_002478a8 {
public:
    Elem_002478a8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_002478a8(Buf_002478a8 *b, unsigned n, const Elem_002478a8 &x, False_002478a8)
{
    Elem_002478a8 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_002478a8 *q = (Elem_002478a8 *)FUN_00002f60(sizeof(Elem_002478a8), p);
        if (q)
            FUN_002469f4(q, x);
        ++p;
        ++b->size;
    }
}
