/* HSTMATCH module=hstp_trans_main.prx start=0x0027c5f0 end=0x0027c6a0 symbol=FUN_0027c5f0 lang=c++ */
/* Clone of src/eboot/enter_state_zero_0026b674.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_003751d4;
extern "C" void FUN_00108e6c(Obj *, float);
extern "C" void FUN_001090f4(Obj *, int);
extern "C" void FUN_0001dc34(int, int);
extern "C" void FUN_0001de88(int, int, int);
extern "C" void FUN_00108f54(Obj *, int);
extern "C" void FUN_0027c6a0(Obj *, int);

extern "C" void FUN_0027c5f0(Obj *s)
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
    FUN_0027c6a0(s, 0);
}
