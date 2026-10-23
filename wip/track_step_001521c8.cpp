/* HSTMATCH module=EBOOT.BIN start=0x001521c8 end=0x001522b4 symbol=FUN_001521c8 lang=c++ */
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
};

extern "C" char *DAT_0034a118;
extern "C" char *DAT_0034a114;
extern "C" void *FUN_001c6f70(void *, int, int);
extern "C" void *FUN_001c70c0(void *);

extern "C" int FUN_001521c8(char *param_1, char *param_2)
{
    Base *p;
    int id;

    if (*(int *)(param_1 + 8) > 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - 1;
        return 0;
    }
    {
        p = *(Base **)(param_2 + 0xc);
        id = *(int *)(param_1 + 4);
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
        return p->v13();
    }
}
//
// 8 words short of 59. Retail duplicates the p load: once in the blezl delay slot (taken path) and
// again as the first instruction of the out-of-line body (0x1521f0); ours loads it only in the delay
// slot. The rest is the same branch/block layout as wip/track_lookup_0015467c.cpp.
// near miss from lane fm6 (unreviewed)
