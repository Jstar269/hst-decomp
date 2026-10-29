/* HSTMATCH module=hstp_trans_main.prx start=0x002702d4 end=0x00270484 symbol=FUN_002702d4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/update_state_0025f4ac.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idiom: the 2-bit mode test is written `(mode != 0) ^ 1` (retail materialises sltu/xori before the branch); the bitfield sits at bits 5:4 of the byte at +0x8b. */
struct Info {  /* record behind Self::info */
    char pad0[0xdc];
    int selected;  /* 0xdc: index 0..2 compared in the highlight loop */
    char pade0[8];
    unsigned char unkE8;
    char pade9;
    unsigned char unkEA;
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
    Info *info;  /* 0x58 */
    char pad5c[8];
    unsigned char enabled;  /* 0x64 */
    char pad65[0x7b];
    int tableValue;  /* 0xe0 */
    char pade4[0x20c];
    char sub2f0[0x2e0];  /* 0x2f0 sub-object passed to the per-index update calls */
    int selectedCopy;  /* 0x5d0 */
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
    if (self->info->unkEA != 0) {
        FUN_001bfc3c(&DAT_003eaad8, 1);
    }
    if (self->enabled == 0 && ((DAT_003751d4->mode != 0) ^ 1)) {
        FUN_001bfc3c(&DAT_003eaad8, 4);
        self->m7();
    } else if (self->info->unkE8 != 0) {
        FUN_001bfc3c(&DAT_003eaad8, 3);
        int sel = self->info->selected;
        self->tableValue = DAT_002dadb4[sel];
        self->selectedCopy = sel;
        if (FUN_000bde14(sel) != 0) {
            FUN_0026f4c0(self, 1);
        } else {
            FUN_0026f4c0(self, 2);
        }
    }
    int current = self->info->selected;
    for (int i = 0; i < 3; i++) {
        if (i == current) {
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
