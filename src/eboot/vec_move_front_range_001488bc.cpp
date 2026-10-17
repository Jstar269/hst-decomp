/* HSTMATCH module=EBOOT.BIN start=0x001488bc end=0x00148964 symbol=FUN_001488bc lang=c++ */
/* Clone of src/eboot/vec_move_front_range_000b524c.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements {data, size, capacity, alloc, start}: copy-construct [first, last) backwards
   in front of the current contents (placement new 0x2f60 + copy constructor 0xb43e8), moving start down.
   Same shape as the move loop in 0xb4d00; the by-value tag parameter gives the 48-byte frame. Names provisional. */
struct False_001488bc {};
struct Elem_001488bc { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146a3c(Elem_001488bc *, const Elem_001488bc &);
class Buf_001488bc {
public:
    Elem_001488bc *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001488bc(Buf_001488bc *b, Elem_001488bc *first, Elem_001488bc *last, False_001488bc)
{
    Elem_001488bc *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_001488bc *q = (Elem_001488bc *)FUN_00002f60(sizeof(Elem_001488bc), p);
        if (q)
            FUN_00146a3c(q, *last);
        --b->start;
        ++b->size;
    }
}
