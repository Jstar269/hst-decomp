/* HSTMATCH module=EBOOT.BIN start=0x00286e08 end=0x00286f00 symbol=FUN_00286e08 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual calls, boolean flag reuse with xori, Vec4 assignment to parameter; exact match verified; names and types await human review. */

extern "C" {
extern void *FUN_00022418(void *out, void *a, void *b);
extern void FUN_001cd3d0(void *p);
extern void FUN_001cd3e4(void *p);
}

struct Vec4 {
    float x, y, z, w;
};

struct GlobalData_0034a114 {
    char pad[0xf9];
    unsigned char flagF9;  // +0xf9 (249)
};

extern "C" GlobalData_0034a114 *DAT_0034a114;

struct TargetClass_00286e08 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void *v6();
    virtual void v7(Vec4 *v);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();

    char pad[28];          // 4..31
    Vec4 pos;              // +32 (0x20)
    char pad2[37];         // 48..84
    unsigned char flag55;  // +85 (0x55)
};

extern "C" void FUN_00286e08(TargetClass_00286e08 *self)
{
    Vec4 copy;
    Vec4 r;
    bool b;

    self->v17();
    if (self->flag55 != 0) {
        FUN_001cd3d0(DAT_0034a114);
        FUN_001cd3e4(DAT_0034a114);
    }
    b = self->v11() == 2;
    if (!b) {
        b = self->v11() == 3;
    }
    if (b && DAT_0034a114->flagF9 == 0) {
        FUN_00022418(&r, self->v6(), &self->pos);
        copy = r;
        self->v7(&copy);
    }
}
