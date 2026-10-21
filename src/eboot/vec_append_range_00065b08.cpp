/* HSTMATCH module=EBOOT.BIN start=0x00065b08 end=0x00065b9c symbol=FUN_00065b08 lang=c++ */
/* Clone of src/sharing_main/vec_append_range_00066f5c.cpp (hstclone.py tag c160320): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False {};
struct Elem { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00065b9c(Elem *, const Elem &);
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00065b08(Buf *b, Elem *first, Elem *last, False)
{
    Elem *p = b->data + b->size;
    for (; first != last; ++first) {
        Elem *q = (Elem *)FUN_00002f60(sizeof(Elem), p);
        if (q)
            FUN_00065b9c(q, *first);
        ++p;
        ++b->size;
    }
}
