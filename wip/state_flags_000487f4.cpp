/* HSTMATCH module=EBOOT.BIN start=0x000487f4 end=0x000489e0 symbol=FUN_000487f4 lang=c++ */
extern int DAT_0034b328;
extern int DAT_0034a850;
extern int DAT_0034b350;
extern int DAT_00338ac4;
extern unsigned char DAT_00341771;
extern int DAT_003415d4;
extern int DAT_002cfc8c;

extern "C" int FUN_0029e0e0(void);
extern "C" int FUN_00296920(void);
extern "C" int FUN_00190724(void);

extern "C" bool FUN_000487f4(void)
{
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    bool b5 = false;
    bool b6 = false;
    bool r = false;

    if (DAT_0034b328 != 0)
        r = FUN_0029e0e0() != 0;
    if (!r) {
        r = true;
        if (DAT_0034a850 != 0 && FUN_00296920() == 0)
            r = false;
        if (r)
            b1 = true;
    }
    if (b1) {
        r = DAT_0034b350 == 0;
        if (!r)
            r = *(int *)(DAT_0034b350 + 0x5d0) == 0;
        if (r)
            b2 = true;
    }
    if (b2 && DAT_00338ac4 == 0)
        b3 = true;
    if (b3 && DAT_00341771 == 0)
        b4 = true;
    if (b4) {
        r = true;
        if (DAT_003415d4 != 0 && FUN_00190724() == 0)
            r = false;
        if (r)
            b5 = true;
    }
    if (b5 && *(int *)(DAT_002cfc8c + 0x80) == 0x308)
        b6 = true;
    if (b6)
        r = ((int)*(char *)(DAT_002cfc8c + 0x88) << 0x18) >> 0x1e == 0;
    else
        r = false;
    return r;
}
// 0x000487f4: 106/123 words, 119 differ. Chain of 8 bool flags (b1..b6,r), each stage
// `if (!r) {...}` / `if (b1) {...}`. Retail materialises every global test as a bool
// (sltu r,zero,X; xori r,1) before branching, so the source assigns bool locals per test
// (e.g. `bool present = G != 0; if (!present) ...`), and the 8 flags are initialised in the
// order s5,s4,s3,s2,s1,s6,s7,s0 while `return r` reads s5 (the first-initialised).
// Ours folds the tests into direct beqz/bnez. Ruled out: the plain Ghidra transcription.
// near miss from lane fm11 (unreviewed)
