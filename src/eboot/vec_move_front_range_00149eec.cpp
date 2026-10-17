/* HSTMATCH module=EBOOT.BIN start=0x00149eec end=0x00149f94 symbol=FUN_00149eec lang=c++ */
/* Clone of src/eboot/vec_move_front_range_000b524c.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 80-byte elements {data, size, capacity, alloc, start}: copy-construct [first, last) backwards
   in front of the current contents (placement new 0x2f60 + copy constructor 0xb43e8), moving start down.
   Same shape as the move loop in 0xb4d00; the by-value tag parameter gives the 48-byte frame. Names provisional. */
struct False_00149eec {};
struct Elem_00149eec { int w[20]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00147430(Elem_00149eec *, const Elem_00149eec &);
class Buf_00149eec {
public:
    Elem_00149eec *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00149eec(Buf_00149eec *b, Elem_00149eec *first, Elem_00149eec *last, False_00149eec)
{
    Elem_00149eec *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_00149eec *q = (Elem_00149eec *)FUN_00002f60(sizeof(Elem_00149eec), p);
        if (q)
            FUN_00147430(q, *last);
        --b->start;
        ++b->size;
    }
}
