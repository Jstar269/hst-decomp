/* HSTMATCH module=EBOOT.BIN start=0x00095104 end=0x000952f8 symbol=FUN_00095104 lang=c++ */
// NEAR MISS 113/125 words (the plain-C variant of the same body reached
// 121/125; it is in try/lane-work/s095104.c unchanged).  Open deltas: retail
// uses SIX s-registers (s5 = this, s4..s1 = the four parameters, s0 = the
// returned char) and zeroes the 8-byte local pair right before its stores;
// this build keeps `this` in s0 and needs only five.  The two 64-byte buffers
// are at sp+48 and sp+112 with buf1 the one passed as the second argument.
// The 8-byte zeroing is a local struct with a default ctor (inline memset
// `li 8; sb zero` loop) declared where the source uses it, not a hoisted
// prologue initialiser.
struct Pair {
    void *a;
    void *b;
    Pair() { a = 0; b = 0; }
};
extern "C" void FUN_000952f8(int, int, void *, void *, int);
extern "C" void FUN_00053b04(int, void *, void *, int);
extern "C" void *DAT_002beb50[];

extern "C" char FUN_00095104(int *param_1, int param_2, int param_3, short param_4, unsigned char param_5)
{
    char r;
    unsigned char bufB[64];
    unsigned char bufA[64];

    (*(void (**)(int *))(*param_1 + 0x14))(param_1);
    param_1[0x6c] = 6;
    param_1[0x6d] = -1;
    *(short *)(param_1 + 0x6e) = 0;
    *(unsigned char *)((int)param_1 + 0x1ba) = 0;
    param_1[0x6c] = param_2;
    param_1[0x6d] = param_3;
    *(short *)(param_1 + 0x6e) = param_4;
    if (param_1[0x6c] == 0 || param_1[0x6c] == 5)
        param_5 = 0;
    *(unsigned char *)((int)param_1 + 0x1ba) = param_5;
    if (param_1[0x6d] < 0)
        return 0;
    FUN_000952f8(param_1[0x6c], param_1[0x6d], bufA, bufB,
                 *(unsigned char *)((int)param_1 + 0x1ba));
    r = (*(char (**)(int *, void *, void *, int, int, int, int))(*param_1 + 0x10))
            (param_1, bufA, bufB, 0, 0, 0, 1);
    if (r == 0 && *(unsigned char *)((int)param_1 + 0x1ba) != 0 && param_1[0x6c] != 2) {
        *(unsigned char *)((int)param_1 + 0x1ba) = 0;
        FUN_000952f8(param_1[0x6c], param_1[0x6d], bufA, bufB, 0);
        r = (*(char (**)(int *, void *, void *, int, int, int, int))(*param_1 + 0x10))
                (param_1, bufA, bufB, 0, 0, 0, 1);
    }
    if (r != 0 && (unsigned int)(param_1[0x6c] - 1) < 2 && *(short *)(param_1 + 0x6e) != 0) {
        Pair p;
        p.a = DAT_002beb50[0];
        p.b = DAT_002beb50[*(short *)(param_1 + 0x6e)];
        FUN_00053b04(param_1[0x23], bufB, &p, 1);
    }
    return r;
}
// near miss from lane fm8 (unreviewed)
