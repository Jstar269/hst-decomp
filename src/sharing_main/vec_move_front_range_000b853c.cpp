/* HSTMATCH module=hstp_trans_main.prx start=0x000b853c end=0x000b85e4 symbol=FUN_000b853c lang=c++ */
/* Clone of src/eboot/vec_move_front_range_000b524c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements {data, size, capacity, alloc, start}: copy-construct [first, last) backwards
   in front of the current contents (placement new 0x2f60 + copy constructor 0xb43e8), moving start down.
   Same shape as the move loop in 0xb4d00; the by-value tag parameter gives the 48-byte frame. Names provisional. */
struct False_000b853c {};
struct Elem_000b853c { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000b76d8(Elem_000b853c *, const Elem_000b853c &);
class Buf_000b853c {
public:
    Elem_000b853c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000b853c(Buf_000b853c *b, Elem_000b853c *first, Elem_000b853c *last, False_000b853c)
{
    Elem_000b853c *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_000b853c *q = (Elem_000b853c *)FUN_00002f60(sizeof(Elem_000b853c), p);
        if (q)
            FUN_000b76d8(q, *last);
        --b->start;
        ++b->size;
    }
}
