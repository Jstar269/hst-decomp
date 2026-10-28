/* HSTMATCH module=EBOOT.BIN start=0x000383f4 end=0x000384d4 symbol=FUN_000383f4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g1) corrected by hand: two 0x36714 calls, packed 0x55/0x58 halves, tail call. */
extern "C" void FUN_00042054(char *obj, int size);
extern "C" int *FUN_00036714(char *a0, int a1, int a2);
extern "C" unsigned int FUN_0002c78c(int a0);
extern "C" int FUN_000419f4(int a0, int a1, unsigned int a2);
extern "C" int FUN_00041cd4(int a0, int a1, int a2, int a3, int a4, char *a5);

extern "C" int FUN_000383f4(char *self, int a1, int a2, int a3, int a4, int a5)
{
    char *base = self + 8;
    int *rec;
    unsigned int r;

    FUN_00042054(self, 20);
    rec = FUN_00036714(base, a1, a3);
    FUN_00036714((char *)rec, a2, a4);
    r = FUN_0002c78c(a5);
    unsigned int hi = (r >> 24) | 0x58000000;
    unsigned int lo = (r & 0x00ffffff) | 0x55000000;
    rec[1] = hi;
    rec[0] = lo;
    return FUN_00041cd4(FUN_000419f4((int)(rec + 2), 1, hi), 1, 0x800102, 2, 0, base);
}

// NEAR 53/56 words (lane dsn2, DeepSeek V4.1 Flash (Freebuff)) - TWIN of 0x0003807c: identical apart from
// the FUN_00041cd4 mode constant (`li a1,1` here, `li a1,6` at 0x3807c) and the addresses. The same source
// gives the same 56/56-word length and the same 53-word diff at the same first offset (+0x4), so fixing
// 0x0003807c_near.cpp (s6 = a0+8 live range, the `ins` field-clear idiom, MWCC's tail-call pass) fixes this
// one too. See the longer note in wip/FUN_0003807c_near.cpp.
// near miss from lane dsn2 (unreviewed)
