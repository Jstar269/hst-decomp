/* HSTMATCH module=EBOOT.BIN start=0x0026b724 end=0x0026b850 symbol=FUN_0026b724 lang=c++ */
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
    int state;
    SubObj *p60;
    SubObj *p64;
    int f68;
    int f6c;
};

extern char DAT_0034179c;
extern int DAT_0034a120;
extern int DAT_0034b328;
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0001f21c(int, void *);
extern "C" void FUN_0010b6d4(SubObj *, int, int);
extern "C" void FUN_001b3ea4(float, void *);
extern "C" void *FUN_0029a8bc(void *);
extern "C" void FUN_0029dfdc(int);

extern "C" void FUN_0026b724(Obj *o, int state)
{
    void *p;
    o->state = state;
    switch (state) {
    case 0:
        o->f55 = 0;
        o->p60->v1(0);
        o->p64->v1(1);
        o->p58->v1(0);
        o->p58->v10();
        FUN_0010b6d4(o->p58, 0, 1);
        o->p58->v6(3001.0f);
        o->f68 = 0;
        break;
    case 1:
        o->p58->v1(1);
        FUN_001b3ea4(0.5f, &DAT_0034179c);
        o->f6c = 0;
        break;
    case 2:
        p = FUN_00000bcc(0x40);
        if (p) {
            p = FUN_0029a8bc(p);
        }
        FUN_0001f21c(DAT_0034a120, p);
        FUN_0029dfdc(DAT_0034b328);
        break;
    }
}
