/* HSTMATCH module=EBOOT.BIN start=0x0025141c end=0x00251604 symbol=FUN_0025141c lang=c++ */
// NEAR MISS 115/122 words.  Open deltas: retail hoists `lbu DAT_002fbef8` above
// the clamp (the then-block reads the flag before the clamp), keeps the clamp
// result in a2 (ours a1), and the then-block's tail (the `lb` at table+4 that
// returns when negative) is not in Ghidra's pseudocode -- added by hand here.
// The two `lw lo` loads match with a reference-taking inline
// Clamp(const int &, const int &, const int &).
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" int FUN_001c7158(void);
extern "C" void FUN_00250f68(int, int, int);
extern "C" unsigned char DAT_002fbef8;
extern "C" unsigned char DAT_002fbef9;
extern "C" int DAT_002fbef4;
extern "C" int DAT_002fcbd0;
extern "C" int DAT_002fcbd4;
extern "C" int DAT_002fcbd8;
extern "C" int DAT_002fcbdc;
extern "C" int DAT_003415a8;
extern "C" int DAT_0034a780;

extern "C" void FUN_0025141c(int param_1)
{
    unsigned int u;
    int v;
    int b;

    u = FUN_001c7158();
    *(unsigned int *)(param_1 + 0x30c) = u & 0xff;
    if ((u & 0xff) == 0) {
        v = *(int *)(param_1 + 0x304);
        v = Clamp(v, DAT_002fcbd0, DAT_002fcbd4);
        *(int *)(param_1 + 0x304) = v;
        DAT_002fbef4 = v;
        if (*(signed char *)(DAT_0034a780 * 6 + ((DAT_002fbef8 != 0) ^ 1) * 0x60
                             + DAT_003415a8 + 0x86c14) < 0)
            return;
    } else {
        b = *(signed char *)(DAT_0034a780 * 6 + ((DAT_002fbef8 != 0) ^ 1) * 0x60
                             + DAT_003415a8 + 0x86c13);
        v = Clamp(b, DAT_002fcbd8, DAT_002fcbdc);
        if (v < 0 || DAT_002fbef9 != 0)
            FUN_00250f68(param_1, 0xffffffff,
                         DAT_002fbef9 == 0 && DAT_002fbef8 != 0);
        else
            FUN_00250f68(param_1, v, DAT_002fbef8 != 0);
    }
}
// near miss from lane fm8 (unreviewed)
