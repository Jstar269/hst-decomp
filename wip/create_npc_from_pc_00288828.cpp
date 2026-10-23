/* HSTMATCH module=EBOOT.BIN start=0x00288828 end=0x002889cc symbol=FUN_00288828 lang=c++ */
struct Game { char pad[0x4c]; int *npc; };
extern "C" Game *DAT_0034a114;
extern "C" char DAT_002feac8[];
extern "C" char DAT_002feaa0[];
extern "C" char DAT_002fea64[];
extern "C" char DAT_002fe9c8[];
extern "C" char DAT_002fea94[];
extern "C" void FUN_00286acc(char *, ...);
extern "C" int FUN_00000bcc(unsigned);
extern "C" int FUN_001268d8(int);
extern "C" void FUN_001c6908(int, int, void *);
extern "C" void FUN_000143b0(void *, char *, int, int);
extern "C" void FUN_0014c028(int, int);
extern "C" int FUN_00155f34(int, void *);
extern "C" int FUN_00014a40(void *);
extern "C" int FUN_00000a90(unsigned);
extern "C" void FUN_000149a8(int, void *);
extern "C" int FUN_0014c274(int, char *);
extern "C" void FUN_000943d0(int, int);
extern "C" void FUN_002869cc(int, char *, int);

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void start(int, int, int, int);
};

extern "C" void FUN_00288828(int param_1, int param_2, int param_3)
{
    char buf[256];
    int p;
    int q;
    int exist;

    exist = *(int *)(((int *)DAT_0034a114)[0x13] + (int)(param_1 * sizeof(int)));
    if (exist != 0) {
        FUN_00286acc(DAT_002feaa0, param_1, param_2);
        return;
    }
    {
        FUN_00286acc(DAT_002feac8, param_1, param_2);
        p = FUN_00000bcc(0x420);
        if (p != 0)
            p = FUN_001268d8(p);
        *(int *)(p + 0x110) = param_1;
        *(int *)(p + 0x114) = param_3;
        *(int *)(p + 0x118) = param_2;
        ((Sub *)(p + 0xe0))->start(2, param_2, 0, 0);
        q = p;
        if (p != 0)
            q = p + 0xe0;
        FUN_001c6908((int)DAT_0034a114, param_1, (void *)q);
        FUN_000143b0(buf, DAT_002fea64, *(int *)(DAT_0034a114->pad + 0xcc) + 1, param_1);
        if (*(int *)(p + 0xe4) != 0) {
            FUN_0014c028(*(int *)(p + 0xe4), 1);
            *(int *)(p + 0xe4) = 0;
        }
        *(int *)(p + 0xe4) = FUN_00155f34(*(int *)(DAT_0034a114->pad + 0x3c), buf);
        q = FUN_00014a40(buf);
        *(int *)(p + 0xf0) = FUN_00000a90(q + 1);
        FUN_000149a8(*(int *)(p + 0xf0), buf);
        if (*(int *)(p + 0xe4) != 0)
            *(int *)(p + 0x11c) = FUN_0014c274(*(int *)(p + 0xe4), DAT_002fe9c8);
        FUN_000943d0(p, 5);
        FUN_002869cc(p + 0xe0, DAT_002fea94, 0);
    }
}
// near miss: 105/105 words, 7 differ -- all in the table-entry test at the top. Retail computes
// `lui v1,0x35; lw v1,-24300(v1); ... lw v1,76(v1); addu v1,v1,a0; lw v1,0(v1); beqz v1` with the
// index shift in a0 (`sll a0,s3,2`); ours uses v0 for the chain and v1 for the shift.
// Ruled out (all byte-identical): a struct-pointer global with `->npc[param_1]`, `int x[0x13]`
// indexing, index-first `param_1*4 + tab`, `param_1 << 2`, sizeof(int) scale, a named `int exist`
// load, a named `int *tab`, `if (entry != 0) {print; return;}` vs if/else (layout is the same
// either way, so the early-return form is kept). The rest of the function is exact, including the
// 6-argument virtual call, the 256-byte buffer at sp+0x20 and the duplicated `sw s3,272(s0)`.
// near miss from lane fm8 (unreviewed)
