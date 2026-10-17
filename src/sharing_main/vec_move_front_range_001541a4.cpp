/* HSTMATCH module=hstp_trans_main.prx start=0x001541a4 end=0x0015424c symbol=FUN_001541a4 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_000b524c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements {data, size, capacity, alloc, start}: copy-construct [first, last) backwards
   in front of the current contents (placement new 0x2f60 + copy constructor 0xb43e8), moving start down.
   Same shape as the move loop in 0xb4d00; the by-value tag parameter gives the 48-byte frame. Names provisional. */
struct False_001541a4 {};
struct Elem_001541a4 { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152324(Elem_001541a4 *, const Elem_001541a4 &);
class Buf_001541a4 {
public:
    Elem_001541a4 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001541a4(Buf_001541a4 *b, Elem_001541a4 *first, Elem_001541a4 *last, False_001541a4)
{
    Elem_001541a4 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_001541a4 *q = (Elem_001541a4 *)FUN_00002f60(sizeof(Elem_001541a4), p);
        if (q)
            FUN_00152324(q, *last);
        --b->start;
        ++b->size;
    }
}
