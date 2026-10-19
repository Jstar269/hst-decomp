/* HSTMATCH module=EBOOT.BIN start=0x0016b85c end=0x0016b90c symbol=FUN_0016b85c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Pair {
    char pad0[1];
    unsigned char f1;
};

struct Elem {
    char pad0[4];
    Pair pair;
    char pad1[50];
};

extern int DAT_002e0470;
extern int DAT_002e0474;
extern "C" Elem *FUN_0016bb88(int a0, int a1);

static inline int ClampTo(int v, const int &lo, const int &hi)
{
    if (v < lo)
        return lo;
    return (v > hi) ? hi : v;
}

extern "C" void FUN_0016b85c(int idx, int value)
{
    Elem *t = FUN_0016bb88(idx, value);
    unsigned short val = (unsigned short)ClampTo((unsigned short)value, DAT_002e0470, DAT_002e0474);
    int i = (unsigned short)idx;
    Pair *pp;

    if (i >= 0 && i < 15)
        pp = &t[i].pair;
    else
        pp = 0;
    pp->f1 = val;
}
