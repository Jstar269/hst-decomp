/* HSTMATCH module=EBOOT.BIN start=0x001fc3dc end=0x001fc4e8 symbol=FUN_001fc3dc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: typed members and ctor results, `p = operator new(n); if (p) p = ctor(p);` allocation pattern, lui/addiu module addresses passed as symbol addresses; exact match verified; names and types await human review. */
struct A { char pad[0x60]; };
struct B { char pad[0x94]; };
struct C { char pad[0x80]; };
struct D { char pad[0x470]; };
struct Self {
    char pad[0x3c];
    B *m3c;
    C *m40;
    A *m44;
    D *m48;
};
extern char DAT_002ef01c[];
extern char DAT_002ef028[];
extern char DAT_0030ebf4[];
extern D *DAT_003403f8;
extern "C" void FUN_00000020(void *);
extern "C" void FUN_00000028();
extern "C" void FUN_0001cad0(void *, int, void *);
extern "C" void FUN_0001cb88(void *);
extern "C" A *FUN_001fba78(A *);
extern "C" B *FUN_001fbfa8(B *);
extern "C" C *FUN_001fbbd0(C *);
extern "C" D *FUN_00159f08(D *, int);
extern "C" void FUN_00103628(A *, int);

extern "C" void FUN_001fc3dc(Self *self, int flag) {
    FUN_00000020(DAT_002ef01c);
    FUN_0001cad0(DAT_0030ebf4, 1, DAT_002ef028);
    A *a = (A *)operator new(0x60);
    if (a) a = FUN_001fba78(a);
    self->m44 = a;
    FUN_00103628(a, 1);
    if (flag == 0) {
        B *b = (B *)operator new(0x94);
        if (b) b = FUN_001fbfa8(b);
        self->m3c = b;
        C *c = (C *)operator new(0x80);
        if (c) c = FUN_001fbbd0(c);
        self->m40 = c;
    }
    FUN_0001cb88(DAT_0030ebf4);
    if (flag == 0) {
        if (DAT_003403f8) {
            self->m48 = DAT_003403f8;
        } else {
            D *d = (D *)operator new(0x470);
            if (d) d = FUN_00159f08(d, 0);
            self->m48 = d;
        }
    }
    FUN_00000028();
}
