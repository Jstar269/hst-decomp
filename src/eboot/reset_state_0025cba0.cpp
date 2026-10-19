/* HSTMATCH module=EBOOT.BIN start=0x0025cba0 end=0x0025ccb4 symbol=FUN_0025cba0 lang=c++ */
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
    char pad56[2];
    SubObj *p58;
    void *p5c;
    char pad60[0x3c8 - 0x60];
    int f3c8;
};

struct Res {
    virtual void v0();
    virtual void v1();
};

struct Dat3386c8 {
    char pad[0x44];
    unsigned char f44;
};

extern int DAT_002cfc8c;
extern Dat3386c8 *DAT_003386c8;
extern unsigned char DAT_003417be;

extern "C" void FUN_00103540(Obj *, float);
extern "C" void FUN_001037c8(Obj *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_00103628(Obj *, int);
extern "C" void FUN_00280830(void *, int, int);
extern "C" void FUN_0025ccfc(Obj *, int);
extern "C" Res *FUN_0008d994(Dat3386c8 *);

extern "C" void FUN_0025cba0(Obj *s)
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
    FUN_00103540(s, 99990.0f);
    FUN_001037c8(s, -1);
    FUN_00280830(s->p5c, 0, 1);
    DAT_003386c8->f44 = 0;
    DAT_003417be = 0;
    FUN_0025ccfc(s, 0);
    Res *res = FUN_0008d994(DAT_003386c8);
    res->v1();
    s->f3c8 = 0;
}
