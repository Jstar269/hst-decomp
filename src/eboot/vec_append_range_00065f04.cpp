/* HSTMATCH module=EBOOT.BIN start=0x00065f04 end=0x00065fa0 symbol=FUN_00065f04 lang=c++ */
/* Clone of src/sharing_main/vec_append_range_00067358.cpp (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False_00065f04 {};
struct Elem_00065f04 { int w[3]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00065b9c(Elem_00065f04 *, const Elem_00065f04 &);
class Buf_00065f04 {
public:
    Elem_00065f04 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00065f04(Buf_00065f04 *b, Elem_00065f04 *first, Elem_00065f04 *last, False_00065f04)
{
    Elem_00065f04 *p = b->data + b->size;
    for (; first < last; ++first) {
        Elem_00065f04 *q = (Elem_00065f04 *)FUN_00002f60(sizeof(Elem_00065f04), p);
        if (q)
            FUN_00065b9c(q, *first);
        ++p;
        ++b->size;
    }
}
