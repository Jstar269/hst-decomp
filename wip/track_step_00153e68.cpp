/* HSTMATCH module=EBOOT.BIN start=0x00153e68 end=0x00153f54 symbol=FUN_00153e68 lang=c++ */
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

extern "C" int FUN_00153e68(char *param_1, char *param_2)
{
    Base *p;
    int id;

    if (*(int *)(param_1 + 0xc) > 0) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - 1;
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
// 8 words short of 59; same family/issue as wip/track_step_001521c8.cpp (count at +0xc instead of +8).
// Retail duplicates the p load at the body start and the DAT_0034a114 luis; ours keeps one copy.
// near miss from lane fm6 (unreviewed)
