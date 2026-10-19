/* HSTMATCH module=hstp_trans_main.prx start=0x0029dc88 end=0x0029dda8 symbol=FUN_0029dc88 lang=c++ */
/* Clone of src/eboot/check_records_0028c4c0.cpp (hstclone.py tag bp1018ar1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the loop condition is an inline helper taking an empty Tag by value (that is what reserves
   retail's 16-byte frame slot and materialises the compare as an int), the result variable is declared before
   the cursor, and the mode test is a 4-case switch rather than an || chain (an || chain becomes a range check). */

struct Rec {
    int pad0[5];
    int f14;
    int f18;
    float f1c;
    char pad1[0x60 - 0x20];
};

struct Vec {
    Rec *beg;
    int count;
};

struct Tag {};

static inline bool AtEnd(Rec *p, Rec *end, Tag)
{
    return !(p == end);
}

extern "C" int FUN_0023ba3c(int mode, int arg, int param);

extern "C" int FUN_0029dc88(Vec *v, int arg)
{
    int ok = 1;
    Rec *p = v->beg;

    while (AtEnd(p, v->beg + v->count, Tag())) {
        if (!(p->f1c < 0.99f)) {
            int mode = p->f14;
            int any = 1;
            switch (mode) {
            case 12:
            case 13:
            case 14:
            case 15:
                any = 0;
                break;
            }
            if (any) {
                if (FUN_0023ba3c(mode, p->f18, arg) == 0) {
                    ok = 0;
                    break;
                }
            }
        }
        p++;
    }
    return ok;
}
