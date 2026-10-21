/* HSTMATCH module=EBOOT.BIN start=0x000ce954 end=0x000ceaa4 symbol=FUN_000ce954 lang=c++ */
#pragma opt_common_subs off

extern "C" void FUN_0001f06c();
extern "C" void FUN_000007f4(void *p, void *f1, void *f2, int sz, int n);
extern "C" void FUN_00056b98();
extern "C" void FUN_00056cb0();
extern "C" void FUN_000143b0(char *buf, const char *fmt, const char *path, void *arg);
extern "C" void FUN_000573a0(void *p, int a, char *buf, int b, int c);
extern "C" void FUN_00057b58(void *p, int a, float f, int b);
extern "C" void FUN_00058ddc(void *p, int a, int b);
extern "C" void FUN_00053f30(int h);

extern char DAT_00307520[];
extern char DAT_002d635c[];
extern char DAT_002d6368[];
extern char DAT_002c0480[];
extern void *DAT_002d6358[];

struct Sub_ce954 {
    virtual void s0();
    virtual void s1();
    virtual void s2(char *name, int a, int b, int c, int d, int e);
    char pad0[0x88];
    int f_cc;
    char pad1[0x30];
    unsigned char f100;
    char pad2[0xef];
};

struct Obj_ce954 {
    char pad0[0x3c];
    unsigned char f3c;
    char pad1[3];
    Sub_ce954 subs[3];
};

extern "C" Obj_ce954 *FUN_000ce954(Obj_ce954 *self)
{
    char buf[256];
    FUN_0001f06c();
    *(void **)self = (void *)DAT_00307520;
    self->f3c = 0;
    FUN_000007f4(&self->subs[0], (void *)FUN_00056b98, (void *)FUN_00056cb0, 0x1b0, 3);
    char *base = (char *)self;
    unsigned i = 0;
    void **p = DAT_002d6358;
    int off = 0;
    do {
        FUN_000143b0(buf, DAT_002d635c, DAT_002c0480, *p);
        ((Sub_ce954 *)(base + off + 0x40))->s2(buf, 0, 0, 0, 0, 0);
        FUN_000143b0(buf, DAT_002d6368, DAT_002c0480, *p);
        FUN_000573a0(base + off + 0x40, 0, buf, 0, 0);
        FUN_00057b58(base + off + 0x40, 0, 0.0f, 0);
        FUN_00058ddc(base + off + 0x40, 1, -1);
        char *pos = base + off;
        *(unsigned char *)(pos + 0x100) = 1;
        FUN_00053f30(*(int *)(pos + 0xcc));
        i++;
        p++;
        off += 0x1b0;
    } while (i == 0);
    return self;
}
// NEAR MISS: 84/84 words, 4 words differ - the last block wants addu v0,s3,s0 / li a1,1 / sb a1,256(v0)
// while we emit addu v1,s3,s0 / li v0,1 / sb v0,256(v1) (same for the lw a0,204(v0) in the jal delay slot).
// Ruled out: no `char *pos` local (recomputes the addu -> 1 extra word, 18 off); default CSE (mwcc then keeps
// base+off and +0x40 in s4/s5 across the calls -> 6 saved regs, 79 off); `*(unsigned char *)(pos+0x100)=1;`,
// `int one = 1; pos[0x100] = one;` (byte-identical); `while (i<1)` (loop deleted, 70 words); `DAT_002d6358[i]`
// instead of a `void **p` walk (s0/s1 swapped). Needs #pragma opt_common_subs off for the cross-call CSE.
// Remaining lever: which of v0/a1 holds the stored constant 1.
// near miss from lane ds10 (unreviewed)
