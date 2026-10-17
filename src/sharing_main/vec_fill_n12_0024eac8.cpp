/* HSTMATCH module=hstp_trans_main.prx start=0x0024eac8 end=0x0024ebb8 symbol=FUN_0024eac8 lang=c++ */
/* Clone of src/eboot/vec_fill_n12_0023e930.cpp (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (element copy and tag as in src/eboot/vec_append_range12_002463a8.cpp); exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};

struct Elem {
    float v[3];
};

struct Buf {
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};

extern "C" {
void FUN_00003ed4(void *, int);
void FUN_00003370(void *, int, int, int, int, fwd_tag);

void FUN_0024eac8(Buf *b, unsigned n, Elem *x)
{
    fwd_tag tag;
    Elem *p = b->data + b->start + b->size;
    for (; n != 0; --n) {
        if (p != 0) {
            if ((*(int *)x & 1) == 0) {
                *p = *x;
            } else {
                p->v[0] = 0.0f;
                p->v[1] = 0.0f;
                p->v[2] = 0.0f;
                FUN_00003ed4(p, *(int *)&x->v[1]);
                FUN_00003370(p, 0, 0, *(int *)&x->v[2], *(int *)&x->v[2] + *(int *)&x->v[1], tag);
            }
        }
        ++p;
        ++b->size;
    }
}
}
