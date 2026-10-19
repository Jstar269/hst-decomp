/* HSTMATCH module=hstp_trans_main.prx start=0x002a0bc4 end=0x002a0c98 symbol=FUN_002a0bc4 lang=c++ */
/* Clone of src/eboot/mode_switch_virtual_calls_0028f3fc.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_0029fdb0(Self *);
extern "C" void FUN_0026a188(Self *);
extern "C" VC4 *FUN_0008f170(void *);
extern "C" VC13 *DAT_003e1a00;
extern "C" void *DAT_003e1a08;

extern "C" void FUN_002a0bc4(Self *o) {
    if (o->d8() == 0) return;
    DAT_003e1a00->m12(1);
    switch (o->mode) {
    case 0:
    case 3:
        FUN_0029fdb0(o);
        FUN_0026a188(o);
        break;
    case 1:
    case 2:
    case 4:
        FUN_0026a188(o);
        FUN_0008f170(DAT_003e1a08)->m3();
        break;
    }
}
