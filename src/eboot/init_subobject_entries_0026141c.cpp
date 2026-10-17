/* HSTMATCH module=EBOOT.BIN start=0x0026141c end=0x002615a8 symbol=FUN_0026141c lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a7/v21/FUN_0026141c.c (tag: a7) */
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
extern int DAT_00331b88;
extern int DAT_003415ac;
extern void FUN_00063d08(int, int, float, float);
extern void FUN_00103128(Self *);
extern void FUN_00103480(Self *);
extern void FUN_00103628(int, int);
extern int FUN_001155c0(int);
extern void FUN_0025e698(Self *, int);
extern void FUN_0025f4ac(Self *);
extern void FUN_0025f65c(Self *);
extern void FUN_00261d70(void *);

void FUN_0026141c(Self *self)
{
    if (self->v8() == 0) {
        return;
    }
    FUN_00103128(self);
    switch (self->state) {
    case 0:
        FUN_0025f4ac(self);
        FUN_00261d70(&self->tail_sub);
        FUN_00103480(self);
        break;
    case 2:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_00103628(DAT_003415ac, 1);
            FUN_0025e698(self, 0);
        }
        break;
    case 1:
        if (self->count == 0x27) {
            FUN_00063d08(DAT_00331b88, 0xf, 65535.0f, 200000.0f);
        }
        if (self->count >= 0x28) {
            FUN_0025e698(self, 3);
        }
        self->sub->s15();
        self->sub->s11();
        self->sub->s11();
        break;
    case 3:
        FUN_0025f65c(self);
        break;
    case 4:
        FUN_0025e698(self, 0);
        break;
    }
    self->count++;
}
}
