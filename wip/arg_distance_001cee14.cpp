/* HSTMATCH module=EBOOT.BIN start=0x001cee14 end=0x001cef8c symbol=FUN_001cee14 lang=c++ */
extern float DAT_002ea2dc;
extern float DAT_002ea2e0;
extern void *DAT_0034a118;
extern "C" float FUN_0000c5bc(float);

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Arg {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void *m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual int m11();
    char vpad[0x30];
    int f34;
    char pad[0x1c];
    unsigned char f54;
};

struct Self {
    char pad[0x20];
    Vec4 f20;
    Vec4 f30;
    float f40;
};

extern "C" Vec4 FUN_00022434(void *, void *);
extern "C" void FUN_00022518(Vec4 *, Vec4 *);
extern "C" float FUN_000224d8(Vec4 *, Vec4 *);

extern "C" bool FUN_001cee14(Self *self, Arg *arg) {
    if (arg->f54 != 0 && arg->m11() == 3 && (DAT_0034a118 == 0 || arg != (Arg *)((char *)DAT_0034a118 + 0xe0)) && arg->f34 < 1000) {
        Vec4 a = FUN_00022434(arg->m6(), &self->f30);
        Vec4 b;
        FUN_00022518(&b, &a);
        b.w = 0.0f;
        Vec4 d = b;
        float v = FUN_000224d8(&self->f20, &d);
        float c;
        if (v < DAT_002ea2dc) c = DAT_002ea2dc;
        else if (v > DAT_002ea2e0) c = DAT_002ea2e0;
        else c = v;
        return FUN_0000c5bc(c) < self->f40;
    }
    return false;
}
// NEAR 4 words (90/94). Structure, branch polarity and every call match; what differs:
//  - stack temp slots: retail a@16, b@32, copy-of-a@48, copy-of-b@64; MWCC gives a@16, d@32, b@48, copy@64
//    for every declaration/copy order tried (declaring `Vec4 c = a;` explicitly adds a fifth temp, frame 96).
//  - clamp: retail loads the bound into f12 AND f1 (`lwc1 f12,A; lwc1 f1,A; c.lt.s f0,f1`), ours CSEs into one
//    f12 load; the ternary spelling is worse (98 words). Retail also keeps a stranded `mov.s f12,f0` after the
//    taken `b`, i.e. the scheduler's leftovers are part of the original stream.
//  - tail: retail has a second `move v0,zero; lw ra` block at 0x1cef74 shared by all early returns; ours
//    branches to a single epilogue with `move v0,zero` in the delay slot.
// Ruled out: bool vs int return, `if` chain vs single `&&` condition (the && form is what matched the prologue).
// near miss from lane ds10 (unreviewed)
