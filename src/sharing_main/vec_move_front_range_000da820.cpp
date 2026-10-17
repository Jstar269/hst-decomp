/* HSTMATCH module=hstp_trans_main.prx start=0x000da820 end=0x000da8c8 symbol=FUN_000da820 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_000d6b30.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_000da820 {};
struct Elem_000da820 { int w[6]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000d9638(Elem_000da820 *, const Elem_000da820 &);
class Buf_000da820 {
public:
    Elem_000da820 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000da820(Buf_000da820 *b, Elem_000da820 *first, Elem_000da820 *last, False_000da820)
{
    Elem_000da820 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_000da820 *q = (Elem_000da820 *)FUN_00002f60(sizeof(Elem_000da820), p);
        if (q)
            FUN_000d9638(q, *last);
        --b->start;
        ++b->size;
    }
}
