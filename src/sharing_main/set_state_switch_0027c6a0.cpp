/* HSTMATCH module=hstp_trans_main.prx start=0x0027c6a0 end=0x0027c7cc symbol=FUN_0027c6a0 lang=c++ */
/* Clone of src/eboot/set_state_switch_0026b724.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_003eaad8;
extern int DAT_003f3458;
extern int DAT_003f4668;
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0001ef34(int, void *);
extern "C" void FUN_001118ac(SubObj *, int, int);
extern "C" void FUN_001c2130(float, void *);
extern "C" void *FUN_002a9b40(void *);
extern "C" void FUN_002ad158(int);

extern "C" void FUN_0027c6a0(Obj *o, int state)
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
        FUN_001118ac(o->p58, 0, 1);
        o->p58->v6(3001.0f);
        o->f68 = 0;
        break;
    case 1:
        o->p58->v1(1);
        FUN_001c2130(0.5f, &DAT_003eaad8);
        o->f6c = 0;
        break;
    case 2:
        p = FUN_00000bcc(0x40);
        if (p) {
            p = FUN_002a9b40(p);
        }
        FUN_0001ef34(DAT_003f3458, p);
        FUN_002ad158(DAT_003f4668);
        break;
    }
}
