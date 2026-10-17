/* HSTMATCH module=hstp_trans_main.prx start=0x001548b8 end=0x00154960 symbol=FUN_001548b8 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_00148fd0.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct False_001548b8 {};
struct Elem_001548b8 { int w[10]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_00152704(Elem_001548b8 *, const Elem_001548b8 &);
class Buf_001548b8 {
public:
    Elem_001548b8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_001548b8(Buf_001548b8 *b, Elem_001548b8 *first, Elem_001548b8 *last, False_001548b8)
{
    Elem_001548b8 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_001548b8 *q = (Elem_001548b8 *)FUN_00002f60(sizeof(Elem_001548b8), p);
        if (q)
            FUN_00152704(q, *last);
        --b->start;
        ++b->size;
    }
}
