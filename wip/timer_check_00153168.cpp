/* HSTMATCH module=EBOOT.BIN start=0x00153168 end=0x001532e4 symbol=FUN_00153168 lang=c++ */
extern "C" {
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
}

struct Obj {
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual int state();
};

extern "C" int FUN_00153168(int param_1, int param_2)
{
    Obj *obj;
    int id;
    int n;
    float d;

    n = *(int *)(param_1 + 8);
    if (n > 0) {
        *(int *)(param_1 + 8) = n - 1;
        return 0;
    }
    n = *(int *)(param_1 + 0xc) - 1;
    *(int *)(param_1 + 0xc) = n;
    if (n <= 0)
        return 1;
    obj = (Obj *)*(int *)(param_2 + 0xc);
    id = *(int *)(param_1 + 4);
    if (id == -1) {
        obj = (Obj *)DAT_0034a118;
        if (DAT_0034a118 != 0)
            obj = (Obj *)(DAT_0034a118 + 0xe0);
    } else if (id >= 0) {
        if (id < 100)
            obj = (Obj *)*(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            obj = (Obj *)FUN_001c6f70(DAT_0034a114, id, 0);
        else
            obj = (Obj *)FUN_001c70c0(DAT_0034a114);
    }
    if (obj == 0)
        return 1;
    if (obj->state() != 2 && obj->state() != 3)
        return 0;
    if (obj != 0)
        obj = (Obj *)((char *)obj - 0xe0);
    d = *(float *)((char *)obj + 0x1e4) - *(float *)((char *)obj + 0x1e8);
    if (d < 0.0f)
        d = -d;
    if (d < 0.001f)
        return 1;
    return 0;
}
// near miss: 93/95 words. Semantics and the whole tail are recovered (family: countdown at +8 and
// +0xc, the 0x34 vcall tested != 2 then != 3, `if (obj != 0) obj -= 0xe0`, then
// fabsf(+0x1e4 - +0x1e8) < 0.001f -> 1). Open: retail emits `blezl` with the +0xc load in the
// delay slot and does the store as `sw v0,8(a0)`, ours emits a plain `blez` plus an
// `addiu v1,a0,8; sw v0,0(v1)` address temp -- same shape for the second counter. The lookup
// chain also carries the family's `bgezl a1` duplicated-guard form.
// near miss from lane fm6 (unreviewed)
