/* HSTMATCH module=EBOOT.BIN start=0x0025f4ac end=0x0025f65c symbol=FUN_0025f4ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern int DAT_002ca7f4[];
extern Glob *DAT_002cfc8c;
extern int DAT_003386c8;
extern char DAT_0034179c;
int FUN_001b1c44(char *, int);
int FUN_000baaa4(int);
void FUN_0025e698(Self *, int);
void FUN_00261bbc(char *, int);
void FUN_00261c24(char *, int);
void FUN_0025336c(int, int);
void *FUN_0008d994(int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
}

extern "C" void FUN_0025f4ac(Self *self)
{
    if (self->info->unkEA != 0) {
        FUN_001b1c44(&DAT_0034179c, 1);
    }
    if (self->enabled == 0 && ((DAT_002cfc8c->mode != 0) ^ 1)) {
        FUN_001b1c44(&DAT_0034179c, 4);
        self->m7();
    } else if (self->info->unkE8 != 0) {
        FUN_001b1c44(&DAT_0034179c, 3);
        int sel = self->info->selected;
        self->tableValue = DAT_002ca7f4[sel];
        self->selectedCopy = sel;
        if (FUN_000baaa4(sel) != 0) {
            FUN_0025e698(self, 1);
        } else {
            FUN_0025e698(self, 2);
        }
    }
    int current = self->info->selected;
    for (int i = 0; i < 3; i++) {
        if (i == current) {
            FUN_00261bbc(self->sub2f0, i);
        } else {
            FUN_00261c24(self->sub2f0, i);
        }
    }
    FUN_0025336c(8, 1);
    FUN_00103540(100000.0f, FUN_0008d994(DAT_003386c8));
    FUN_001037c8(FUN_0008d994(DAT_003386c8), -1);
    ((VC_1 *)FUN_0008d994(DAT_003386c8))->m();
}
