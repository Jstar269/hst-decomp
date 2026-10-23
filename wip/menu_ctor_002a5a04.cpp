/* HSTMATCH module=EBOOT.BIN start=0x002a5a04 end=0x002a5c18 symbol=FUN_002a5a04 lang=c++ */
#pragma opt_strength_reduction off
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, const char *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00050fc0(void *);
extern "C" void *FUN_001039d8(void *, const char *, int);
extern "C" void *FUN_001026b8(void *, const char *);
extern char DAT_00309f58[];
extern char DAT_00301010[];
extern const char *const DAT_00300b54[];
extern char DAT_00300d44[];
extern const int DAT_00300fd8[];

struct Actor {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int v);
    unsigned char pad[0x400];
};

struct Res {
    unsigned char pad0[0x20];
    Actor *f20;
};

struct Fn {
    int idx;
    const char *name;
    int res;
};

struct Blk {
    int a[4];
    int b[4];
};

struct Obj {
    void *vt;
    unsigned char pad04[0x54 - 4];
    void *slot4[4];
    void *f64[55];
    Actor *f140[14];
    Actor *f178;
    unsigned char b17c;
    unsigned char pad17d[0x880 - 0x17d];
    int f880;
    int f884;
    int f888;
    int f88c;
    int f890;
    int f894;
    Blk blk[102];
    unsigned char b1558;
    unsigned char pad1559[0x1700 - 0x1559];
    void *f1700;
};

extern "C" Obj *FUN_002a5a04(Obj *self)
{
    Fn *fn;
    Actor *a;
    const char *const *tab;
    int off;
    int i;
    int n;
    int k;
    struct Blk *e;
    struct Blk *end;

    FUN_00102e38(self);
    self->vt = DAT_00309f58;

    e = self->blk;
    end = e + 102;
    do {
        for (k = 0; k < 4; k++) {
            e->a[k] = 0;
            e->b[k] = 0;
        }
        e++;
    } while (e < end);

    FUN_00104118(self, DAT_00301010, 0);
    FUN_00103540(self, 1000.0f);

    n = (int)FUN_00000bcc(0x48);
    if (n != 0) {
        n = (int)FUN_00050fc0((void *)n);
    }
    self->f1700 = (void *)n;

    off = 0;
    tab = DAT_00300b54;
    for (i = 0; i < 4; i++, tab++, off += 4) {
        a = (Actor *)FUN_001039d8(self, *tab, 0);
        *(void **)((char *)self + off + 0x54) = a;
        a->m5(-2048);
    }

    fn = (Fn *)DAT_00300d44;
    off = 0;
    for (i = 0; i < 55; i++) {
        Res *r = (Res *)FUN_001026b8(self->slot4[fn->idx], fn->name);
        *(void **)((char *)self + off + 0x64) = r;
        fn->res = *(int *)((char *)r + 0x24);
        off += 4;
        fn++;
    }

    off = 0;
    for (i = 0; i < 14; i++) {
        a = ((Res *)self->f64[DAT_00300fd8[i]])->f20;
        *(Actor **)((char *)self + off + 0x140) = a;
        a->m5(-1808);
        off += 4;
    }

    self->b17c = 0;
    a = ((Res *)self->f64[0])->f20;
    self->f178 = a;
    a->m5(-16);

    a = self->f178;
    *(int *)((char *)a + 0xd8) = 0;
    *(unsigned char *)((char *)a + 0x114) = 1;
    a->m1();

    self->f880 = 0;
    self->b1558 = 0;
    self->f884 = 9;
    self->f888 = 0;
    self->f88c = 0;
    self->f890 = 0;
    self->f894 = 0;
    return self;
}
// NEAR 65/133 words, function #2 of batch fm4-00.
// Matched shapes (verified by diff): the 3264-byte clear at +0x898 is `e = self->blk; end = e + 102;
// do { for (k = 0; k < 4; k++) { e->a[k] = 0; e->b[k] = 0; } e++; } while (e < end);` over
// struct Blk { int a[4], b[4]; } - the inner 4-iteration loop is what produces retail's interleaved
// store order 0,16,4,20,8,24,12,28, and the do/while gives the peeled first block + `bnezl` with the
// next block's word 0 in the delay slot. `#pragma opt_strength_reduction off` is REQUIRED for the three
// index loops: with it on, mwcc turns `*(void **)((char *)self + off + 0x54)` into a walking pointer
// (`sw a0,84(s1)` with s1 = self+off) instead of retail's `addu v1,s0,s1; sw v0,84(v1)`.
// Alloc/ctor tail: `n = FUN_00000bcc(0x48); if (n != 0) n = FUN_00050fc0(n); self->f1700 = n;` gives
// retail's plain `beqz v0` + `move a0,v0` (a ternary gives a branch-likely form).
// WHAT DIFFERS: the saved-register colours of the two long-lived values - retail has self in s0 (its
// `move s0,a0` sits in the first jal's delay slot) and the loop counter i in s3, ours the reverse
// (self s3, i s0); the rest of the body is instruction-identical modulo those names, and the vptr store
// vs the clear loop's `addiu a0` swap places in the prologue as a consequence.
// Ruled out: declaration-order permutations (i first / last / block-scoped loop counters), block-scoping
// the loop pointers, `for (e = ...; e < end; e++)` (adds an entry test), index loop with 102 count
// (slti + base register instead of the two-pointer sltu).
// near miss from lane fm4 (unreviewed)
