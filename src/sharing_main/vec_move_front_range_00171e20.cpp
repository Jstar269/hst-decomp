/* HSTMATCH module=hstp_trans_main.prx start=0x00171e20 end=0x00171ec8 symbol=FUN_00171e20 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_00165c30.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00171e20 {};
struct Elem_00171e20 { int w[139]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_001712dc(Elem_00171e20 *, const Elem_00171e20 &);
class Buf_00171e20 {
public:
    Elem_00171e20 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00171e20(Buf_00171e20 *b, Elem_00171e20 *first, Elem_00171e20 *last, False_00171e20)
{
    Elem_00171e20 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_00171e20 *q = (Elem_00171e20 *)FUN_00002f60(sizeof(Elem_00171e20), p);
        if (q)
            FUN_001712dc(q, *last);
        --b->start;
        ++b->size;
    }
}
