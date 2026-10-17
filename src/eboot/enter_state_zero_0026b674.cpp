/* HSTMATCH module=EBOOT.BIN start=0x0026b674 end=0x0026b724 symbol=FUN_0026b674 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct SubObj {
    virtual void v0();
    virtual void v1(int);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

struct Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    char pad[0x50];
    unsigned char f54;
    unsigned char f55;
    SubObj *p58;
};

extern int DAT_002cfc8c;
extern "C" void FUN_00103540(Obj *, float);
extern "C" void FUN_001037c8(Obj *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_00103628(Obj *, int);
extern "C" void FUN_0026b724(Obj *, int);

extern "C" void FUN_0026b674(Obj *s)
{
    FUN_00103540(s, 1010.0f);
    FUN_001037c8(s, -1);
    FUN_0001dfe8(DAT_002cfc8c, 0x2000);
    FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
    if (s->p58) {
        s->p58->v10();
    }
    s->f54 = 1;
    s->f55 = 0;
    FUN_00103628(s, 0);
    s->s2();
    FUN_0026b724(s, 0);
}
