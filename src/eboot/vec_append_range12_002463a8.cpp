/* HSTMATCH module=EBOOT.BIN start=0x002463a8 end=0x00246484 symbol=FUN_002463a8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed 12-byte float array element, derived fwd_tag local, and batched lwc1/swc1 copies; exact match verified; names and types await human review. */

struct in_tag {};
struct fwd_tag : in_tag {};

struct Elem {
    float v[3];
};

struct Vec {
    Elem *data;
    int size;
    unsigned capacity;
};

extern "C" {
void FUN_00003ed4(void *, int);
void FUN_00003370(void *, int, int, int, int, fwd_tag);

void FUN_002463a8(Vec *v, Elem *first, Elem *last)
{
    fwd_tag tag;
    Elem *cur = v->data + v->size;
    for (; first != last; first++) {
        if (cur != 0) {
            if ((*(int *)first & 1) == 0) {
                *cur = *first;
            } else {
                cur->v[0] = 0.0f;
                cur->v[1] = 0.0f;
                cur->v[2] = 0.0f;
                FUN_00003ed4(cur, *(int *)&first->v[1]);
                FUN_00003370(cur, 0, 0, *(int *)&first->v[2], *(int *)&first->v[2] + *(int *)&first->v[1], tag);
            }
        }
        cur++;
        v->size++;
    }
}
}
