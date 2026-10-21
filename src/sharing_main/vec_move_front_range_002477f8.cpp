/* HSTMATCH module=hstp_trans_main.prx start=0x002477f8 end=0x002478a8 symbol=FUN_002477f8 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_002376c0.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_002477f8 {};
struct Elem_002477f8 { int w[140]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_002469f4(Elem_002477f8 *, const Elem_002477f8 &);
class Buf_002477f8 {
public:
    Elem_002477f8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_002477f8(Buf_002477f8 *b, Elem_002477f8 *first, Elem_002477f8 *last, False_002477f8)
{
    Elem_002477f8 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_002477f8 *q = (Elem_002477f8 *)FUN_00002f60(sizeof(Elem_002477f8), p);
        if (q)
            FUN_002469f4(q, *last);
        --b->start;
        ++b->size;
    }
}
