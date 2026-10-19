/* HSTMATCH module=EBOOT.BIN start=0x0028c4c0 end=0x0028c5e0 symbol=FUN_0028c4c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the loop condition is a functor temporary carrying the comparison (`NotAtEnd()(p, end)`),
   which is what reserves retail's 16-byte frame slot and materialises the compare as an int; the result
   variable is declared before the cursor; the mode test is a 4-case switch rather than an || chain (an
   || chain is strength-reduced to a range check). */

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

struct NotAtEnd {
    bool operator()(Rec *p, Rec *end) const { return !(p == end); }
};

extern "C" int FUN_0022bfcc(int mode, int arg, int param);

extern "C" int FUN_0028c4c0(Vec *v, int arg)
{
    int ok = 1;
    Rec *p = v->beg;

    while (NotAtEnd()(p, v->beg + v->count)) {
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
                if (FUN_0022bfcc(mode, p->f18, arg) == 0) {
                    ok = 0;
                    break;
                }
            }
        }
        p++;
    }
    return ok;
}
