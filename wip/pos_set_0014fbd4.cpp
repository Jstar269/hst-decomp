/* HSTMATCH module=EBOOT.BIN start=0x0014fbd4 end=0x0014fd94 symbol=FUN_0014fbd4 lang=c++ */
extern "C" int DAT_0034a114;
extern "C" int DAT_0034a118;
extern "C" float DAT_002bc440[4];
extern "C" unsigned char DAT_003402f0;
extern "C" char DAT_002dc374[];
extern "C" int FUN_001c6f70(int, int, int);
extern "C" int FUN_001c70c0(int);
extern "C" int FUN_001caee4(int, int, void *, void *);
extern "C" void FUN_00022418(void *, float *, void *);
extern "C" void FUN_0014d044(int);
extern "C" void FUN_0014fd94(char *, int);

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void setPos(Vec4 *);
    virtual void v4();
    virtual void v5();
    virtual void setRot(Vec4 *);
};

extern "C" int FUN_0014fbd4(int param_1, int param_2)
{
    Vec4 d;
    Vec4 c;
    Vec4 b;
    Vec4 a;
    int *p;
    int id;

    p = *(int **)(param_2 + 0xc);
    id = *(int *)(param_1 + 8);
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
    if (FUN_001caee4(DAT_0034a114, *(int *)(param_1 + 0xc), &d, &c) == 0) {
        d.x = DAT_002bc440[0];
        d.y = DAT_002bc440[1];
        d.z = DAT_002bc440[2];
        d.w = DAT_002bc440[3];
        b.x = 0.0f;
        b.z = 0.0f;
        b.y = 1.0f;
        b.w = 0.0f;
        FUN_00022418(&a, DAT_002bc440, &b);
        c = a;
    }
    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc374, *(int *)(param_1 + 8));
    }
    if (p != 0) {
        ((Obj *)p)->setPos(&d);
        ((Obj *)p)->setRot(&c);
    }
    return 0;
}
// near miss: 107/112 (5 short) -- the id-lookup family blocker again (`bltz a1` where retail has
// `bgezl a1` + the duplicated `slti at,a1,100` in the delay).
// Everything else matches: the Vec4 slots must be declared d,c,b,a so the frame gives d=0x40,
// c=0x30, b=0x20, a=0x10; the fail path copies 0x2bc440..44c into d, builds b = {0,1,0,0} with the
// 0x3f800000 word store, calls FUN_00022418(&a,&DAT_002bc440,&b) and then assigns c = a; the two
// virtual calls are vtable 0x1c with &d and 0x24 with &c on the looked-up object.
// near miss from lane fm8 (unreviewed)
