/* HSTMATCH module=EBOOT.BIN start=0x000d6bd8 end=0x000d6c80 symbol=FUN_000d6bd8 lang=c++ */
/* Clone of src/sharing_main/vec_fill_n_000da8c8.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_000d6bd8 {};
struct Elem_000d6bd8 { int w[6]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000d5948(Elem_000d6bd8 *, const Elem_000d6bd8 &);
class Buf_000d6bd8 {
public:
    Elem_000d6bd8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000d6bd8(Buf_000d6bd8 *b, unsigned n, const Elem_000d6bd8 &x, False_000d6bd8)
{
    Elem_000d6bd8 *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        Elem_000d6bd8 *q = (Elem_000d6bd8 *)FUN_00002f60(sizeof(Elem_000d6bd8), p);
        if (q)
            FUN_000d5948(q, x);
        ++p;
        ++b->size;
    }
}
