/* HSTMATCH module=EBOOT.BIN start=0x0025f4ac end=0x0025f65c symbol=FUN_0025f4ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
    if (self->f58->fea != 0) {
        FUN_001b1c44(&DAT_0034179c, 1);
    }
    if (self->b64 == 0 && ((DAT_002cfc8c->mode != 0) ^ 1)) {
        FUN_001b1c44(&DAT_0034179c, 4);
        self->m7();
    } else if (self->f58->fe8 != 0) {
        FUN_001b1c44(&DAT_0034179c, 3);
        int x = self->f58->fdc;
        self->fe0 = DAT_002ca7f4[x];
        self->f5d0 = x;
        if (FUN_000baaa4(x) != 0) {
            FUN_0025e698(self, 1);
        } else {
            FUN_0025e698(self, 2);
        }
    }
    int cur = self->f58->fdc;
    for (int i = 0; i < 3; i++) {
        if (i == cur) {
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
