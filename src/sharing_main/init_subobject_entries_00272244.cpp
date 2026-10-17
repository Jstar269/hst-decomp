/* HSTMATCH module=hstp_trans_main.prx start=0x00272244 end=0x002723d0 symbol=FUN_00272244 lang=c++ */
/* Clone of src/eboot/init_subobject_entries_0026141c.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a7/v21/FUN_00272244.c (tag: a7) */
struct Sub {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(); // +44 = 8+4*9 -> slot 9 is +44! Wait: +52 is 8+4*11 (slot 11), +68 is 8+4*15 (slot 15)
    virtual void s11(); // +52
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15(); // +68
};

struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8(); // +40 = 8+4*8
    char pad[0x58 - 4];
    Sub *sub;       // +0x58 (88)
    int pad5c;      // +0x5c
    int state;      // +0x60 (96)
    int pad64;      // +0x64
    int count;      // +0x68 (104)
    char pad6c[0x2f0 - 0x6c];
    int tail_sub;   // +0x2f0 (752)
};

extern "C" {
extern int DAT_003daec8;
extern int DAT_003ea8ec;
extern void FUN_00064bcc(int, int, float, float);
extern void FUN_00108a2c(Self *);
extern void FUN_00108dac(Self *);
extern void FUN_00108f54(int, int);
extern int FUN_001204dc(int);
extern void FUN_0026f4c0(Self *, int);
extern void FUN_002702d4(Self *);
extern void FUN_00270484(Self *);
extern void FUN_00272b98(void *);

void FUN_00272244(Self *self)
{
    if (self->v8() == 0) {
        return;
    }
    FUN_00108a2c(self);
    switch (self->state) {
    case 0:
        FUN_002702d4(self);
        FUN_00272b98(&self->tail_sub);
        FUN_00108dac(self);
        break;
    case 2:
        if (FUN_001204dc(DAT_003ea8ec) != 0) {
            FUN_00108f54(DAT_003ea8ec, 1);
            FUN_0026f4c0(self, 0);
        }
        break;
    case 1:
        if (self->count == 0x27) {
            FUN_00064bcc(DAT_003daec8, 0xf, 65535.0f, 200000.0f);
        }
        if (self->count >= 0x28) {
            FUN_0026f4c0(self, 3);
        }
        self->sub->s15();
        self->sub->s11();
        self->sub->s11();
        break;
    case 3:
        FUN_00270484(self);
        break;
    case 4:
        FUN_0026f4c0(self, 0);
        break;
    }
    self->count++;
}
}
