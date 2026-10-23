/* HSTMATCH module=EBOOT.BIN start=0x0015467c end=0x0015474c symbol=FUN_0015467c lang=c++ */
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
};

extern "C" char *DAT_0034a118;
extern "C" char *DAT_0034a114;
extern "C" void *FUN_001c6f70(void *, int, int);
extern "C" void *FUN_001c70c0(void *);

extern "C" int FUN_0015467c(char *param_1, char *param_2)
{
    Base *p = *(Base **)(param_2 + 0xc);
    int id = *(int *)(param_1 + 4);

    if (id == -1) {
        p = (Base *)DAT_0034a118;
        if (p != 0)
            p = (Base *)((char *)p + 0xe0);
    } else if (id >= 0) {
        if (id < 100)
            p = *(Base **)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            p = (Base *)FUN_001c6f70(DAT_0034a114, id, 0);
        else
            p = (Base *)FUN_001c70c0(DAT_0034a114);
    }
    if (p == 0)
        return 1;
    return p->v10();
}

// 7 words short of retail's 52 (45/52 words). Retail tests the -1 arm first, then `bgezl a1,L2` with
// `slti at,a1,100` in the delay AND repeated at L2 (the duplicated branch-likely delay value), plus an
// extra `b JOIN; nop` for the (empty) id<0 arm; ours emits `bltz a1,JOIN` with the body inline.
// Ruled out: `id > -1`, nested `else { if (id >= 0) }`, `p + 0x38` vs `(char*)p + 0xe0`, and the
// two-armed if written in the -1-first / >=0-first orders.
// near miss from lane fm6 (unreviewed)
