/* HSTMATCH module=EBOOT.BIN start=0x001cdf18 end=0x001ce020 symbol=FUN_001cdf18 lang=c++ */
extern "C" {
int FUN_001cde28(int h);
int FUN_001ce028(void *self, int h);
int FUN_001ce020(int h);
void FUN_000542e8(void *dst, int v, void *src);
void FUN_000c3f38(void *dst, const void *src);
float FUN_001cdda8(void *self, const void *src);
float FUN_001cdd68(float *state, const float *lo, const float *hi);
float FUN_0000c5bc(float v);
extern int DAT_0034a118;
extern float DAT_002ea2dc;
extern float DAT_002ea2e0;
}
struct Obj_001cdf18 {
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
    virtual int V4();
    virtual int V5();
    virtual int V6();
};

extern "C" int FUN_001cdf18(char *self, int *handle)
{
    Obj_001cdf18 *h = (Obj_001cdf18 *)*handle;
    int r;
    if (!FUN_001cde28((int)h)) {
        r = 0;
        goto done;
    }
    if (!FUN_001ce028(self, (int)h)) {
        r = 0;
        goto done;
    }
    if (DAT_0034a118 != 0 && (int)h == DAT_0034a118 + 0xe0) {
        r = 0;
        goto done;
    }
    if (FUN_001ce020((int)h) >= 1000) {
        r = 0;
        goto done;
    }
    {
        char buf1[16];
        char buf2[16];
        FUN_000542e8(buf1, h->V6(), self + 0x30);
        FUN_000c3f38(buf2, buf1);
        float v = FUN_001cdda8(self + 0x20, buf2);
        float d = FUN_001cdd68(&v, &DAT_002ea2dc, &DAT_002ea2e0);
        r = FUN_0000c5bc(d) < *(float *)(self + 0x40);
    }
done:
    return r == 0;
}
// NEAR MISS first pass: 70/66 words. Prologue (s0=h, s1=self, frame 64) matches exactly after
// dropping the `int r = 0;` initialiser and zeroing r only on the failure paths; the remaining
// difference is branch shape: retail fails with `beqzl v0, epilogue; move v0,zero` (one branch,
// zero in the delay) plus a shared `move v0,zero` block for checks 2-4, and ends every path in a
// shared `sltu v0,zero,v0; xori v0,v0,1` (i.e. `return r == 0;`). Both the if/else chain and the
// `r = 0; goto done;` chain compile to `bnezl v0,next; ...; b end; move v0,zero` (two branches).
// Ruled out: `bool ok=false; return !ok;` (r hoisted into s0 and self pushed to s2), `int r=0;
// return r==0;`, `bool` return type. The virtual call needs a C++ class (vtable slot 0x20 = 7th
// declared virtual) and the float pair of temps is two 16-byte buffers at sp+16 / sp+32.
// near miss from lane ds11 (unreviewed)
