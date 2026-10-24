/* HSTMATCH module=EBOOT.BIN start=0x001a0bb0 end=0x001a0d78 symbol=FUN_001a0bb0 lang=c++ */
typedef unsigned short ushort;
typedef unsigned char uchar;

struct Target {
    char pad0[0x1038];
    ushort f1038;           /* 0x1038 */
};

struct Globals {
    struct Target *target;  /* 0x00 */
    char pad04[0x1c];       /* 0x04..0x1f */
    int flag;               /* 0x20 */
};

struct Self {
    char pad0[0x116];
    ushort f116;            /* 0x116 */
    char pad118[4];         /* 0x118..0x11b */
    uchar f11c;             /* 0x11c */
    char pad11d[0x1a7];     /* 0x11d..0x2c3 */
    int f2c4;               /* 0x2c4 */
    char pad2c8[0x1c];      /* 0x2c8..0x2e3 */
    int f2e4;               /* 0x2e4 */
    int f2e8;               /* 0x2e8 */
    int f2ec;               /* 0x2ec */
    int f2f0;               /* 0x2f0 */
    int f2f4;               /* 0x2f4 */
    char pad2f8[0x20];      /* 0x2f8..0x317 */
    int f318;               /* 0x318 */
    int f31c;               /* 0x31c */
};

extern "C" {
extern struct Globals DAT_00341ccc;
extern int DAT_002e1b48;
extern int DAT_002e1b4c;
extern char DAT_002e1cd4[];
extern char DAT_002e1ce0[];
extern int FUN_0016b070(int a);
extern int FUN_0016b0c0(int a);
extern void FUN_0019ee24(char *fmt, int val);
extern void FUN_001a444c(struct Self *self);
extern int FUN_001a49dc(struct Self *self, int a);
extern int FUN_001a4a70(struct Self *self, int a);
extern int FUN_001a4af4();
extern void FUN_001c159c(struct Globals *g, int a, int b, int c, int d,
                          int e, int f, int h);
}

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001a0bb0(struct Self *self)
{
    int a, b, c, d;
    struct Globals *g = &DAT_00341ccc;

    if (FUN_001a4af4() != 0) {
        int v = FUN_001a49dc(self, self->f2c4) & 0xffff;
        struct Target *t = g->target;
        t->f1038 = Clamp(v, DAT_002e1b48, DAT_002e1b4c);
    } else {
        int v = (int)self->f116;
        struct Target *t = g->target;
        t->f1038 = Clamp(v, DAT_002e1b48, DAT_002e1b4c);
    }
    FUN_0019ee24(DAT_002e1cd4, FUN_0016b070(self->f2e4));
    FUN_0019ee24(DAT_002e1ce0, FUN_0016b0c0(self->f2ec));
    a = FUN_001a4a70(self, 0);
    b = FUN_001a4a70(self, 1);
    c = FUN_0016b070(self->f2e4);
    d = FUN_0016b0c0(self->f2ec);
    FUN_001c159c(g, self->f318, self->f31c, a, b, self->f2f4,
                 c, d);
    FUN_001a444c(self);
    if (self->f11c == 4)
        g->flag = 0;
    else if (self->f11c == 0)
        g->flag = 0;
    else
        g->flag = 1;
}
// NEAR 113/114 words, 34 differ (structurally identical to retail).
// Fixed: value-then-pointer ordering in each arm gives retail's duplicated
//   clamp store with one shared `lw a0,0(s0)` in the branch delay slot.
// Differs only in: v is a0 here / v1 in retail, target pointer v1 / a0
//   (tried per-arm decl order, top-level decl, declaration-before-assignment:
//    all land on the same swap); FUN_001c159c arg load order (retail loads
//    self->f2f4 into t1 before a1/a2); tail if/else-if shape (retail uses
//    beql a0,4 -> end with annulled delay slot; plain ==4/==0/else and
//    || forms both give our 3-branch chain).
// near miss from lane fm7 (unreviewed)
