/* HSTMATCH module=hstp_trans_main.prx start=0x0026d050 end=0x0026d164 symbol=FUN_0026d050 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/reset_state_0025cba0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern int DAT_003751d4;
extern Dat3386c8 *DAT_003e1a08;
extern unsigned char DAT_003eaaf6;

extern "C" void FUN_00108e6c(Obj *, float);
extern "C" void FUN_001090f4(Obj *, int);
extern "C" void FUN_0001dc34(int, int);
extern "C" void FUN_0001de88(int, int, int);
extern "C" void FUN_00108f54(Obj *, int);
extern "C" void FUN_00291b78(void *, int, int);
extern "C" void FUN_0026d1ac(Obj *, int);
extern "C" Res *FUN_0008f170(Dat3386c8 *);

extern "C" void FUN_0026d050(Obj *s)
{
    FUN_00108e6c(s, 1010.0f);
    FUN_001090f4(s, -1);
    FUN_0001dc34(DAT_003751d4, 0x2000);
    FUN_0001de88(DAT_003751d4, 0x2000, 1);
    if (s->p58) {
        s->p58->v10();
    }
    s->f54 = 1;
    s->f55 = 0;
    FUN_00108f54(s, 0);
    s->s2();
    FUN_00108e6c(s, 99990.0f);
    FUN_001090f4(s, -1);
    FUN_00291b78(s->p5c, 0, 1);
    DAT_003e1a08->f44 = 0;
    DAT_003eaaf6 = 0;
    FUN_0026d1ac(s, 0);
    Res *res = FUN_0008f170(DAT_003e1a08);
    res->v1();
    s->f3c8 = 0;
}
