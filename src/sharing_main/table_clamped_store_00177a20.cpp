/* HSTMATCH module=hstp_trans_main.prx start=0x00177a20 end=0x00177ad0 symbol=FUN_00177a20 lang=c++ */
/* Clone of src/eboot/table_clamped_store_0016b85c.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_00387a2c;
extern int DAT_00387a30;
extern "C" Elem *FUN_00177d4c(int a0, int a1);

static inline int ClampTo(int v, const int &lo, const int &hi)
{
    if (v < lo)
        return lo;
    return (v > hi) ? hi : v;
}

extern "C" void FUN_00177a20(int idx, int value)
{
    Elem *t = FUN_00177d4c(idx, value);
    unsigned short val = (unsigned short)ClampTo((unsigned short)value, DAT_00387a2c, DAT_00387a30);
    int i = (unsigned short)idx;
    Pair *pp;

    if (i >= 0 && i < 15)
        pp = &t[i].pair;
    else
        pp = 0;
    pp->f1 = val;
}
