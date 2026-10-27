/* HSTMATCH module=hstp_trans_main.prx start=0x002702d4 end=0x00270484 symbol=FUN_002702d4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/update_state_0025f4ac.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idiom: the 2-bit mode test is written `(mode != 0) ^ 1` (retail materialises sltu/xori before the branch); the bitfield sits at bits 5:4 of the byte at +0x8b. */
struct Info {
    char pad0[0xdc];
    int fdc;
    char pade0[8];
    unsigned char fe8;
    char pade9;
    unsigned char fea;
};

struct Glob {
    char pad[0x8b];
    signed char lo : 4;
    signed char mode : 2;
};

struct VC_1 {
    virtual void d0();
    virtual void d1();
    virtual void m();
};

struct Self {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    char pad4[0x54];
    Info *f58;
    char pad5c[8];
    unsigned char b64;
    char pad65[0x7b];
    int fe0;
    char pade4[0x20c];
    char sub2f0[0x2e0];
    int f5d0;
};

extern "C" {
extern int DAT_002dadb4[];
extern Glob *DAT_003751d4;
extern int DAT_003e1a08;
extern char DAT_003eaad8;
int FUN_001bfc3c(char *, int);
int FUN_000bde14(int);
void FUN_0026f4c0(Self *, int);
void FUN_002729e4(char *, int);
void FUN_00272a4c(char *, int);
void FUN_002636c0(int, int);
void *FUN_0008f170(int);
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
}

extern "C" void FUN_002702d4(Self *self)
{
    if (self->f58->fea != 0) {
        FUN_001bfc3c(&DAT_003eaad8, 1);
    }
    if (self->b64 == 0 && ((DAT_003751d4->mode != 0) ^ 1)) {
        FUN_001bfc3c(&DAT_003eaad8, 4);
        self->m7();
    } else if (self->f58->fe8 != 0) {
        FUN_001bfc3c(&DAT_003eaad8, 3);
        int x = self->f58->fdc;
        self->fe0 = DAT_002dadb4[x];
        self->f5d0 = x;
        if (FUN_000bde14(x) != 0) {
            FUN_0026f4c0(self, 1);
        } else {
            FUN_0026f4c0(self, 2);
        }
    }
    int cur = self->f58->fdc;
    for (int i = 0; i < 3; i++) {
        if (i == cur) {
            FUN_002729e4(self->sub2f0, i);
        } else {
            FUN_00272a4c(self->sub2f0, i);
        }
    }
    FUN_002636c0(8, 1);
    FUN_00108e6c(100000.0f, FUN_0008f170(DAT_003e1a08));
    FUN_001090f4(FUN_0008f170(DAT_003e1a08), -1);
    ((VC_1 *)FUN_0008f170(DAT_003e1a08))->m();
}
