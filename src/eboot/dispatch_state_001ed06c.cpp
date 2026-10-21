/* HSTMATCH module=EBOOT.BIN start=0x001ed06c end=0x001ed1dc symbol=FUN_001ed06c lang=c++ rodata=0x2c8dd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00338c20;
struct Ret {
    char pad[0x4c];
    int f4c;
};
extern "C" Ret *FUN_000fb810(int);
extern "C" void FUN_001ec564(void *, int, int);
extern "C" int FUN_001fcef4(void *);

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

extern "C" void FUN_001ed06c(Obj *self) {
    switch (self->state) {
    case 3:
        if (FUN_000fb810(DAT_00338c20)->f4c == 5) FUN_001ec564(self, 0, 1);
        break;
    case 4:
        if (FUN_000fb810(DAT_00338c20)->f4c == 5) FUN_001ec564(self, 0, 1);
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
            FUN_001fcef4(FUN_000fb810(DAT_00338c20));
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
