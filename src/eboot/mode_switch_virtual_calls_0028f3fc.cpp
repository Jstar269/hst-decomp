/* HSTMATCH module=EBOOT.BIN start=0x0028f3fc end=0x0028f4d0 symbol=FUN_0028f3fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Self {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual int d8();
    char pad[0x1850 - 4];
    int mode;
};

struct VC13 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12(int);
};

struct VC4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

extern "C" void FUN_0028e5e8(Self *);
extern "C" void FUN_00259cd8(Self *);
extern "C" VC4 *FUN_0008d994(void *);
extern "C" VC13 *DAT_003386c0;
extern "C" void *DAT_003386c8;

extern "C" void FUN_0028f3fc(Self *o) {
    if (o->d8() == 0) return;
    DAT_003386c0->m12(1);
    switch (o->mode) {
    case 0:
    case 3:
        FUN_0028e5e8(o);
        FUN_00259cd8(o);
        break;
    case 1:
    case 2:
    case 4:
        FUN_00259cd8(o);
        FUN_0008d994(DAT_003386c8)->m3();
        break;
    }
}
