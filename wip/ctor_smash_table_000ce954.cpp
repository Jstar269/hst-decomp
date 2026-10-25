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
extern "C" void FUN_00053f30(int h, int b);

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
        int on = i + 1;
        *(unsigned char *)(pos + 0x100) = on;
        FUN_00053f30(*(int *)(pos + 0xcc), on);
        p++;
        off += 0x1b0;
    } while (++i < 1);
    return self;
}
// NEAR MISS (lane sn2): 84/84 words, 1 differs: retail `li a1,1` (one constant register shared by `sb a1,256(v0)` and the 2nd
// argument of FUN_00053f30, which is really (int h, bool on): the callee sets/clears bit 0x10 of a byte from a1); ours below uses the
// non-constant `i + 1` (== 1 on the only iteration) as that shared value, giving `addiu a1,s2,1` - a matching hack, not the source.
// Findings: (1) FUN_00053f30 takes a 2nd argument (callee does `move s5,a1`); with it a literal 1 gives two separate `li` (v0 for the
// store, a1 in the call's slot) under `#pragma opt_common_subs off`; a named constant local, `F(h, p->f = 1)`, an inline helper
// `Act(pos, flag)` and bool/uchar flags all keep them separate (constants are propagated per use).
// (2) With CSE ON the constant IS shared (`li a1,1; sb a1,256(s1); jal; lw a0,204(s1)`) but then base+off and +0x40 are CSE'd into
// s-regs (79 off, 6 saved regs) in every spelling tried: `(unsigned)self + off + 0x40` integer forms, `self->subs[i]` (pointer IV, 54 off).
// (3) `while (++i < 1)` replaces the earlier `while (i == 0)` and `i++` (identical code); pragmas opt_propagation/lifetimes/
// loop_invariants/dead_code/dead_assignments/strength_reduction do not replace opt_common_subs.
// improved by lane sn2 (unreviewed): 4 -> 1 differing words
