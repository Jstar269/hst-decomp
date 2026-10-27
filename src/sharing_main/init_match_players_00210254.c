/* HSTMATCH module=hstp_trans_main.prx start=0x00210254 end=0x002104c4 symbol=FUN_00210254 lang=c99 data=0x00397224 */
/* Clone of src/eboot/init_match_players_00201a84.c (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00397224-0x00397237) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern void *FUN_0020b940(void);
extern float FUN_000957bc(struct Player *);
extern float FUN_00066bb0(void *, char *, int);
extern float FUN_001a22b4(float, float, int);
extern void FUN_000953a8(struct Player *, float);
extern void FUN_000938e0(struct Player *, int);
extern void FUN_0013671c(float, struct Player *, int, int);
extern void FUN_0019fb6c(void *, void *, void *);
extern char *DAT_003f3474;

void FUN_00210254(struct This *self, unsigned char kind, struct Player *a, struct Player *b)
{
    struct Player *p1;
    struct Player *p2;
    void *base;
    int x;
    int y;

    self->f1 = kind;
    self->count = 0;
    void *r = FUN_0020b940();
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
    FUN_0019fb6c(&x, &y, DAT_003f3474 + 0x58);
    p1 = self->p1;
    base = DAT_003f3474 + 0x12c4;
    if (p1 != 0) {
        self->f20 = p1->sub ? p1->sub->f0 : -1;
        self->f28 = self->p1->sub ? self->p1->sub->f8 : 0;
        self->f2c = FUN_000957bc(self->p1);
        self->f34 = self->p1->sub ? self->p1->sub->f104 : 0.0f;
        self->f3c = p1->f32d;
        FUN_0013671c(-1.0f, p1, 0, 1);
        FUN_000953a8(self->p1, FUN_001a22b4(FUN_00066bb0(base, "BaseTall", 1),
                                  FUN_00066bb0(base, "Rating", 1), x));
        FUN_000938e0(p1, -1);
    }
    p2 = self->p2;
    if (p2 != 0) {
        self->f24 = p2->sub ? p2->sub->f0 : -1;
        self->f29 = self->p2->sub ? self->p2->sub->f8 : 0;
        self->f30 = FUN_000957bc(self->p2);
        self->f38 = self->p2->sub ? self->p2->sub->f104 : 0.0f;
        self->f3d = p2->f32d;
        FUN_0013671c(-1.0f, p2, 0, 1);
        FUN_000953a8(self->p2, FUN_001a22b4(FUN_00066bb0(base, "BaseTall", 1),
                                  FUN_00066bb0(base, "Rating", 1), y));
        FUN_000938e0(p2, -1);
    }
}
