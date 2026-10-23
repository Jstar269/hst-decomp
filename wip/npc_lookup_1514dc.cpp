/* HSTMATCH module=EBOOT.BIN start=0x001514dc end=0x00151688 symbol=FUN_001514dc lang=c++ */
extern "C" int DAT_0034a114;
extern "C" int DAT_0034a118;
extern "C" int FUN_001c6f70(int, int, int);
extern "C" int FUN_001c70c0(int);
extern "C" int FUN_00288a84(int *);

struct Obj {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int kind();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int flag();
};

extern "C" bool FUN_001514dc(int *param_1, int *param_2)
{
    int *p;
    int id;
    int *q;
    int v;
    int a;
    int b;
    bool ok;

    if (param_1[3] >= 1) {
        param_1[3]--;
        return false;
    }
    p = (int *)param_2[3];
    id = param_1[1];
    if (id == -1) {
        p = (int *)DAT_0034a118;
        if (p != 0)
            p = (int *)((char *)p + 0xe0);
    } else if (id >= 0) {
        if (id < 100)
            p = *(int **)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            p = (int *)FUN_001c6f70(DAT_0034a114, id, 0);
        else
            p = (int *)FUN_001c70c0(DAT_0034a114);
    }
    if (p == 0)
        return true;
    ok = ((Obj *)p)->kind() == 2;
    if (!ok)
        ok = ((Obj *)p)->kind() == 3;
    if (!ok)
        return true;
    q = (int *)FUN_00288a84(p);
    v = q[0x16];
    a = v != 0 ? *(int *)(v + 0xf0) : -1;
    b = *(int *)(v + 0x110);
    if (a != param_1[2] && b != param_1[2])
        return true;
    return ((Obj *)q)->flag() != 0 && b < 0;
}
// near miss: 94/107 words. The header, the early-out (`param_1[3] >= 1` then `--`), the id==-1
// fallback, the two virtual `kind()` calls (vtable 0x34, index 11), the FUN_00288a84 result's
// +0x58/+0xf0/+0x110 fields and the final `flag() && b < 0` (vtable 0x88, index 32) all match.
// The 5 missing words are the 0x154xxx id-lookup family blocker: retail emits
//   bgezl a1,CHAIN / slti at,a1,100 (in the delay) / b join / nop / slti at,a1,100 (duplicate)
// while we emit `bltz a1,join`. Tested here again: else-if with `id >= 0`, `0 <= id`, `id > -1`,
// nested else { if (id >= 0) } -- all give the plain `bltz` (87-88 differing words).
// NEW: writing the chain FIRST (`if (id >= 0) {..} else if (id == -1) {..}`) DOES produce a likely
// branch (`bltzl a1,CHAIN`, q4.cpp, 93 words), so the likely form is reachable - but that layout
// puts the chain before the id==-1 block, which reverses retail's block order and loses more.
// Typing both params as `int *` and using param_1[3]-- (not `*(int*)(p+0xc) = *(int*)(p+0xc)-1`)
// was required for the `sw v0,12(s0)` store: the flattened form materialises `addiu v1,s0,12`.
// near miss from lane fm8 (unreviewed)
