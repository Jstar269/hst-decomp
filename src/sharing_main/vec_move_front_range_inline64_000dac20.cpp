/* HSTMATCH module=hstp_trans_main.prx start=0x000dac20 end=0x000dacec symbol=FUN_000dac20 lang=c++ */
/* Clone of src/eboot/vec_move_front_range_inline64_000d6f30.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split buffer of 64-byte elements: backward copy of [first,last) in front of the current contents (inlined placement
   new + memberwise float copy). Names provisional. */
struct Elem { float f[16]; };
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
extern "C" void FUN_000dac20(Buf *b, Elem *first, Elem *last)
{
    Elem *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        if (p) {
            p->f[0] = last->f[0];
            p->f[1] = last->f[1];
            p->f[2] = last->f[2];
            p->f[3] = last->f[3];
            p->f[4] = last->f[4];
            p->f[5] = last->f[5];
            p->f[6] = last->f[6];
            p->f[7] = last->f[7];
            p->f[8] = last->f[8];
            p->f[9] = last->f[9];
            p->f[10] = last->f[10];
            p->f[11] = last->f[11];
            p->f[12] = last->f[12];
            p->f[13] = last->f[13];
            p->f[14] = last->f[14];
            p->f[15] = last->f[15];
        }
        --b->start;
        ++b->size;
    }
}
