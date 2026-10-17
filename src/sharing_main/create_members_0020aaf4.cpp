/* HSTMATCH module=hstp_trans_main.prx start=0x0020aaf4 end=0x0020ac00 symbol=FUN_0020aaf4 lang=c++ */
/* Clone of src/eboot/create_members_001fc3dc.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_00397058[];
extern char DAT_00397064[];
extern char DAT_003b7ebc[];
extern D *DAT_003e9738;
extern "C" void FUN_00000020(void *);
extern "C" void FUN_00000028();
extern "C" void FUN_0001c684(void *, int, void *);
extern "C" void FUN_0001c73c(void *);
extern "C" A *FUN_0020a190(A *);
extern "C" B *FUN_0020a6c0(B *);
extern "C" C *FUN_0020a2e8(C *);
extern "C" D *FUN_00166480(D *, int);
extern "C" void FUN_00108f54(A *, int);

extern "C" void FUN_0020aaf4(Self *self, int flag) {
    FUN_00000020(DAT_00397058);
    FUN_0001c684(DAT_003b7ebc, 1, DAT_00397064);
    A *a = (A *)operator new(0x60);
    if (a) a = FUN_0020a190(a);
    self->m44 = a;
    FUN_00108f54(a, 1);
    if (flag == 0) {
        B *b = (B *)operator new(0x94);
        if (b) b = FUN_0020a6c0(b);
        self->m3c = b;
        C *c = (C *)operator new(0x80);
        if (c) c = FUN_0020a2e8(c);
        self->m40 = c;
    }
    FUN_0001c73c(DAT_003b7ebc);
    if (flag == 0) {
        if (DAT_003e9738) {
            self->m48 = DAT_003e9738;
        } else {
            D *d = (D *)operator new(0x470);
            if (d) d = FUN_00166480(d, 0);
            self->m48 = d;
        }
    }
    FUN_00000028();
}
