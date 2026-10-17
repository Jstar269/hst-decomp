/* HSTMATCH module=EBOOT.BIN start=0x002637c8 end=0x002638d8 symbol=FUN_002637c8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual call, declaration order for saved registers, field zeroing in call slot; exact match verified; names and types await human review. */

extern "C" {
extern char DAT_002fdeac[];
extern char DAT_002fdec4[];
extern char DAT_00309ae0[];
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_00010184(int a, int b);
extern void FUN_000104e0(void *p);
extern void FUN_0001bfb4(void *a, void *b, int c);
extern void FUN_0001cad0(void *a, int b, void *c);
extern void FUN_0001cb88(void *a);
extern void *FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void *FUN_0001f06c(void *self);
extern void FUN_00253da0(void);
extern void FUN_00258294(void *p);
extern void *FUN_002638d8(void *p, void *name);
}

struct Obj_002637c8 {
    void *vptr;           // +0
    char pad[56];         // +4 .. +59
    void *f3C;            // +60 (0x3c)
};

struct Target_002637c8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" void *FUN_002637c8(struct Obj_002637c8 *self)
{
    void *iVar1;
    void *uVar3;
    void *p;
    int uVar4;

    FUN_0001f06c(self);
    self->vptr = &DAT_00309ae0;
    self->f3C = 0;
    iVar1 = FUN_00010184(64, 0x300000);
    FUN_0001bfb4(&DAT_0030ab9c, iVar1, 0x300000);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002fdeac);

    p = FUN_00000bcc(0x1e50);
    if (p != 0) {
        p = FUN_002638d8(p, DAT_002fdec4);
    }
    self->f3C = p;

    FUN_00253da0();
    FUN_0001cb88(&DAT_0030ebf4);
    uVar3 = FUN_0001cbfc();
    uVar4 = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c, uVar3, uVar4);

    if (iVar1 != 0) {
        FUN_000104e0(iVar1);
    }

    FUN_00258294(self->f3C);
    ((struct Target_002637c8 *)self->f3C)->v6();

    return self;
}
