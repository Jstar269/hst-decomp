/* HSTMATCH module=hstp_trans_main.prx start=0x001fb3dc end=0x001fb54c symbol=FUN_001fb3dc lang=c++ rodata=0x002d9218 */
/* Clone of src/eboot/dispatch_state_001ed06c.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003e1f60;
struct Ret {
    char pad[0x4c];
    int f4c;
};
extern "C" Ret *FUN_00100f4c(int);
extern "C" void FUN_001fa8a4(void *, int, int);
extern "C" int FUN_0020b614(void *);

struct Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Obj {
    Base *f00;
    Base *f04;
    Base **f08;
    int state;
    int kind;
    int f14;
    int f18;
    unsigned char f1c;
    unsigned char f1d;
    unsigned char f1e;
};

extern "C" void FUN_001fb3dc(Obj *self) {
    switch (self->state) {
    case 3:
        if (FUN_00100f4c(DAT_003e1f60)->f4c == 5) FUN_001fa8a4(self, 0, 1);
        break;
    case 4:
        if (FUN_00100f4c(DAT_003e1f60)->f4c == 5) FUN_001fa8a4(self, 0, 1);
        break;
    }
    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
        self->f00->m3();
        switch (self->kind) {
        case 0:
            (*self->f08)->m3();
            break;
        case 1:
            if (self->f1e == 0) self->f04->m3();
            break;
        case 2:
            break;
        }
        if (self->f1c == 0 && self->kind != 2) {
            FUN_0020b614(FUN_00100f4c(DAT_003e1f60));
        }
        break;
    case 3:
    case 4:
    case 8:
    case 9:
    case 10:
        break;
    }
}
