/* HSTMATCH module=EBOOT.BIN start=0x00201a84 end=0x00201cf4 symbol=FUN_00201a84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the radians conversion must be one direct multiply expression assigned to the member (a local factor puts the constant in the multiply destination FPR); the two player statements use distinct p1/p2 locals (retail reuses s1) and access the member directly for the two later stat reads. */
struct Sub {
    char pad0[0xf0];
    int f0;
    char pad1[4];
    unsigned char f8;
    char pad2[0xb];
    float f104;
};
struct Player {
    char pad0[0x58];
    struct Sub *sub;
    char pad1[0x2d1];
    unsigned char f32d;
};
struct This {
    char pad0[1];
    unsigned char f1;
    char pad1[2];
    int count;
    struct Player *p1;
    struct Player *p2;
    int f10;
    float f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    unsigned char f28;
    unsigned char f29;
    char pad2[2];
    float f2c;
    float f30;
    float f34;
    float f38;
    unsigned char f3c;
    unsigned char f3d;
};

extern void *FUN_001fd170(void);
extern float FUN_00093898(struct Player *);
extern float FUN_000657e4(void *, char *, int);
extern float FUN_00195a18(float, float, int);
extern void FUN_00093484(struct Player *, float);
extern void FUN_00091c48(struct Player *, int);
extern void FUN_0012b2b0(float, struct Player *, int, int);
extern void FUN_0019335c(void *, void *, void *);
extern char DAT_002ef19c[];
extern char DAT_002ef1a8[];
extern char *DAT_0034a13c;

void FUN_00201a84(struct This *self, unsigned char kind, struct Player *a, struct Player *b)
{
    struct Player *p1;
    struct Player *p2;
    void *base;
    int x;
    int y;

    self->f1 = kind;
    self->count = 0;
    void *r = FUN_001fd170();
    float f = *(float *)((char *)r + 0x10) * 0.017453292f;
    self->f10 = 0;
    self->f14 = f;
    self->f18 = 0;
    self->f1c = 0;
    self->p1 = a;
    self->p2 = b;
    if (self->p1 != 0) {
        self->count++;
    }
    if (self->p2 != 0) {
        self->count++;
    }
    x = 0;
    y = 0;
    FUN_0019335c(&x, &y, DAT_0034a13c + 0x58);
    p1 = self->p1;
    base = DAT_0034a13c + 0x12c4;
    if (p1 != 0) {
        self->f20 = p1->sub ? p1->sub->f0 : -1;
        self->f28 = self->p1->sub ? self->p1->sub->f8 : 0;
        self->f2c = FUN_00093898(self->p1);
        self->f34 = self->p1->sub ? self->p1->sub->f104 : 0.0f;
        self->f3c = p1->f32d;
        FUN_0012b2b0(-1.0f, p1, 0, 1);
        FUN_00093484(self->p1, FUN_00195a18(FUN_000657e4(base, DAT_002ef19c, 1),
                                  FUN_000657e4(base, DAT_002ef1a8, 1), x));
        FUN_00091c48(p1, -1);
    }
    p2 = self->p2;
    if (p2 != 0) {
        self->f24 = p2->sub ? p2->sub->f0 : -1;
        self->f29 = self->p2->sub ? self->p2->sub->f8 : 0;
        self->f30 = FUN_00093898(self->p2);
        self->f38 = self->p2->sub ? self->p2->sub->f104 : 0.0f;
        self->f3d = p2->f32d;
        FUN_0012b2b0(-1.0f, p2, 0, 1);
        FUN_00093484(self->p2, FUN_00195a18(FUN_000657e4(base, DAT_002ef19c, 1),
                                  FUN_000657e4(base, DAT_002ef1a8, 1), y));
        FUN_00091c48(p2, -1);
    }
}
