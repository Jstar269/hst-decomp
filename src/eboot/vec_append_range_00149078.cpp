/* HSTMATCH module=EBOOT.BIN start=0x00149078 end=0x00149128 symbol=FUN_00149078 lang=c++ */
/* Clone of src/sharing_main/vec_append_range_00154960.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_00149078 {};
struct Elem_00149078 { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00146e1c(Elem_00149078 *, const Elem_00149078 &);
class Buf_00149078 {
public:
    Elem_00149078 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00149078(Buf_00149078 *b, Elem_00149078 *first, Elem_00149078 *last, False_00149078)
{
    Elem_00149078 *p = b->data + b->start + b->size;
    for (; first < last; ++first) {
        Elem_00149078 *q = (Elem_00149078 *)FUN_00002f60(sizeof(Elem_00149078), p);
        if (q)
            FUN_00146e1c(q, *first);
        ++p;
        ++b->size;
    }
}
