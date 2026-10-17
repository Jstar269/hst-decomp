/* HSTMATCH module=EBOOT.BIN start=0x00059eb8 end=0x00059f60 symbol=FUN_00059eb8 lang=c++ */
/* Clone of src/sharing_main/vec_move_front_range_0005ab70.cpp (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct False_00059eb8 {};
struct Elem_00059eb8 { int w[36]; };
extern "C" void *FUN_00002f60(unsigned, void *);
extern "C" void FUN_000597a0(Elem_00059eb8 *, const Elem_00059eb8 &);
class Buf_00059eb8 {
public:
    Elem_00059eb8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_00059eb8(Buf_00059eb8 *b, Elem_00059eb8 *first, Elem_00059eb8 *last, False_00059eb8)
{
    Elem_00059eb8 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        Elem_00059eb8 *q = (Elem_00059eb8 *)FUN_00002f60(sizeof(Elem_00059eb8), p);
        if (q)
            FUN_000597a0(q, *last);
        --b->start;
        ++b->size;
    }
}
