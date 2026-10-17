/* HSTMATCH module=EBOOT.BIN start=0x000b524c end=0x000b52f4 symbol=FUN_000b524c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements {data, size, capacity, alloc, start}: copy-construct [first, last) backwards
   in front of the current contents (placement new 0x2f60 + copy constructor 0xb43e8), moving start down.
   Same shape as the move loop in 0xb4d00; the by-value tag parameter gives the 48-byte frame. Names provisional. */
struct False_000b524c {};
struct Elem_000b524c { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000b43e8(Elem_000b524c *, const Elem_000b524c &);
class Buf_000b524c {
public:
    Elem_000b524c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000b524c(Buf_000b524c *b, Elem_000b524c *first, Elem_000b524c *last, False_000b524c)
{
    Elem_000b524c *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_000b524c *q = (Elem_000b524c *)FUN_00002f60(sizeof(Elem_000b524c), p);
        if (q)
            FUN_000b43e8(q, *last);
        --b->start;
        ++b->size;
    }
}
