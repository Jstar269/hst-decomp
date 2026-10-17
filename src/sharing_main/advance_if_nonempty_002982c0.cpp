/* HSTMATCH module=hstp_trans_main.prx start=0x002982c0 end=0x00298368 symbol=FUN_002982c0 lang=c++ */
/* Clone of src/eboot/advance_if_nonempty_00286bc4.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the null test of the head node is materialised as a flag (`e = (n != 0) ^ 1; if (e == 0) b = (f14 == &n->sub) ^ 1; else b = e ^ 1;`)
   inside the outer `if (n != 0)`; typed Node pointers (not int + 4) give retail's register pair for the address compare. */
struct Node {
    int pad;
    int sub;
};

struct Sub {
    char pad0[4];
    Node *f4;
    char pad1[0xc];
    int *f14;
};

struct Obj {
    char pad0[8];
    Sub *p8;
    char pad1[0x4d];
    unsigned char f59;
};

extern "C" unsigned char FUN_001584a0(float, Sub *, int);
extern "C" void FUN_00298504(Obj *);

extern "C" unsigned char FUN_002982c0(Obj *o)
{
    if (o->f59 != 0) return 0;
    Sub *s = o->p8;
    Node *n = s->f4;
    int ok = 0;
    if (n != 0) {
        int e = (n != 0) ^ 1;
        int b;
        if (e == 0) b = (s->f14 == &n->sub) ^ 1; else b = e ^ 1;
        if (b) ok = 1;
    }
    if (ok) {
        unsigned char r = FUN_001584a0(1.0f, s, 0);
        if (r) FUN_00298504(o);
        return r;
    }
    return 0;
}
