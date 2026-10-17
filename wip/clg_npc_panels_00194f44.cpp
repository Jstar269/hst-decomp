/* HSTMATCH module=EBOOT.BIN start=0x00194f44 end=0x00195a18 symbol=FUN_00194f44 lang=c++ rodata=0x002c286c */
/* clg_database.cpp (from the Sharing build's asserts): fills the NPC/info panel from a record: copies the
   record into the global at 0x341c54, resolves the two NPC entries (0x1931b8) and the keyed entry, and
   draws them through 0x1c1c50. Names provisional. */
struct Tri { unsigned char a, b, c; };
struct Sh3 { short a, b, c; };
struct Rec {
    Rec();
    char name[16];          /* 0x00 */
    unsigned short x10;     /* 0x10 */
    char name2[16];         /* 0x12 */
    short x22;              /* 0x22 */
    short x24;              /* 0x24 */
    unsigned char x26, x27, x28, x29, x2a, x2b;
    char x2c, x2d;
    unsigned char x2e;
    char x2f;
    unsigned char x30, x31;
    char x32;
    unsigned char x33, x34;
    short x36, x38, x3a, x3c;
    char name3[16];         /* 0x3e */
    char name4[16];         /* 0x4e */
    Tri x5e;
    Sh3 x62;
    short x68, x6a;
};

struct Sub68 { char pad[0x10]; };
struct Entry {
    short id;               /* 0x00 */
    short x2, x4, x6, x8, xa;
    char pad0c[2];
    unsigned char xe;       /* 0x0e */
    char pad0f[0x20 - 0xf];
    unsigned short x20;     /* 0x20 */
    char pad22[0x68 - 0x22];
    Sub68 sub;              /* 0x68 */
    short x78;              /* 0x78 */
    char pad7a[2];
    unsigned char x7c;      /* 0x7c */
    Tri tri[3];             /* 0x7d */
    char pad86[0x9c - 0x86];
};
struct Table { unsigned n; Entry *data; };
struct Node { char pad[0x10]; int value; };
struct It { Node *node; };
struct Map { char pad[4]; Node header; };
struct Owner { char pad[0x30]; Map map; };
struct Base { char pad[0x12]; char x12[1]; };
struct Obj1038 { char pad[0x1038]; short x1038; };
struct Obj138 { char pad[0x138]; int x138; };
struct Info { unsigned short h0, h1, h2, h3; unsigned char x8, x9, xa; };
struct FObj { char pad[4]; float f4; };
struct Flags {
    unsigned char arr[0x1025 + 15];
    int Get(int i) { if (i >= 0 && i < 15) return arr[0x1025 + i]; return 1; }
};
struct Game { char pad[0x80]; Flags flags; };

#define HST_ASSERT(cond, text, line) ((void)0)

extern "C" {
extern Rec DAT_00341c54;
extern char DAT_00341ccc[];
extern int DAT_00341cec;
extern void *DAT_0034a7ec;
extern int DAT_002e13ec, DAT_002e13f0;
extern Table *DAT_00341730;
extern Owner *DAT_00341748;
extern Table *DAT_00341744;
extern Game *DAT_003415a8;
extern int DAT_0034a77c;
extern int DAT_0031101c;

Base *FUN_0022c1c4(void);
int FUN_0027edb4(void *);
int FUN_0027edbc(void *, int);
int FUN_0016b4f0(void);
void FUN_001c159c(void *, int, int, int, int, int, int, int);
Obj1038 *FUN_0016bb88(void);
Obj138 *FUN_0022cd60(void);
void FUN_001931b8(Entry **, Entry **, Rec *);
int FUN_002af920(int);
void FUN_002afa48(int *, int, int);
void FUN_00196478(It *, Map *, const int *);
int FUN_001fea10(int, int, int);
int FUN_0016bb98(int, Sub68 *);
void FUN_001c1c50(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, Sub68 *, int,
                  int, int, int, int, int, int, int, Entry *);
int FUN_0016b164(void);
void FUN_0016b6c8(int);
int FUN_0016b118(void);
int FUN_001ff5d0(int, int);
int FUN_0016b1dc(int);
Info *FUN_0016b3d8(int, int);
int FUN_0016b19c(int);
FObj *FUN_0016b21c(int);
int FUN_0016bb5c(void);
int FUN_0024dd40(float, int);
int FUN_001feac4(int, int);
void FUN_001c19e4(int, int, int, bool, int);
void FUN_001c1d0c(int, int, int, int, int);
}

inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

static inline Entry *Lookup(int key)
{
    if (DAT_00341730) {
        It it;
        FUN_00196478(&it, &DAT_00341748->map, &key);
        if (it.node != &DAT_00341748->map.header)
            return &DAT_00341730->data[it.node->value];
    }
    return 0;
}

static inline Entry *Get(int i)
{
    if (DAT_00341744 && i >= 0 && i < DAT_00341744->n)
        return &DAT_00341744->data[i];
    return 0;
}

extern "C" void FUN_00194f44(Rec *p, int key)
{
    if (p == 0)
        return;
    int lvl = p->x24;
    int c29;
    int idx = p->x22;
    bool b27 = p->x27;
    switch (p->x29) {
    case 1:
    case 3:
    case 5:
        c29 = p->x29 & 0xff;
        break;
    default:
        c29 = 1;
        break;
    }
    int c2a;
    switch (p->x2a) {
    case 2:
    case 4:
    case 6:
        c2a = p->x2a & 0xff;
        break;
    default:
        c2a = 4;
        break;
    }
    if ((short)idx == 0) {
        bool found = false;
        Base *base = FUN_0022c1c4();
        for (int i = 0; i < FUN_0027edb4(DAT_0034a7ec); i++) {
            int id = FUN_0027edbc(DAT_0034a7ec, i);
            if (id && base->x12[id] == 2) {
                idx = i;
                found = true;
                break;
            }
        }
        if (!found)
            idx = 1;
    }
    if (p->x24 == -1)
        lvl = FUN_0016b4f0();
    FUN_001c159c(DAT_00341ccc, 0, 0, p->x2c, p->x2d, p->x2b, c29, c2a);
    Obj1038 *o = FUN_0016bb88();
    o->x1038 = Clamp((unsigned short)idx, DAT_002e13ec, DAT_002e13f0);
    DAT_00341c54 = *p;
    int mode;
    switch (FUN_0022cd60()->x138) {
    case 0:
        mode = 0;
        break;
    case 2:
        mode = 2;
        break;
    default:
        mode = 1;
        break;
    }
    Entry *pNpc1 = 0;
    Entry *pNpc2 = 0;
    FUN_001931b8(&pNpc1, &pNpc2, p);
    switch (p->x28) {
    case 0:
    case 4:
        DAT_00341cec = 0;
        break;
    default:
        DAT_00341cec = 1;
        break;
    }
    int h;
    int t = FUN_002af920(0);
    h = 0;
    FUN_002afa48(&h, 0, t);
    switch (p->x28) {
    case 1:
    case 2:
    case 5:
        if (key) {
            Entry *e = Lookup(key);
            int id = e->id;
            if (id >= 0 && id < 15)
                FUN_001c1c50(2, FUN_001fea10(12, 0, id), id, e->x2, e->x4, e->x6, e->x8, e->xa, 0, 0, 0,
                             e->tri[mode].c, e->tri[mode].a, FUN_0016bb98(id, &e->sub), e->x78, &e->sub, e->x7c,
                             0, 0, e->tri[mode].b, 1, 0, 0, 0, e);
        } else {
            int n = 0;
            int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
            int v = 0;
            if (FUN_0016b164() != 0x7ffe) {
                if (FUN_0016b164() == 0x7fff) {
                    FUN_0016b6c8(0);
                    FUN_0016b6c8(FUN_001ff5d0(FUN_0016b164(), FUN_0016b118()));
                    n = FUN_0016b164();
                    Info *in = FUN_0016b3d8(n, FUN_0016b1dc(n));
                    c0 = in->h0;
                    c1 = in->h1;
                    c2 = in->h2;
                    c3 = in->h3;
                    v = FUN_0016b19c(n);
                } else {
                    FUN_0016b6c8(FUN_001ff5d0(FUN_0016b164(), FUN_0016b118()));
                    n = FUN_0016b164();
                    Info *in = FUN_0016b3d8(n, FUN_0016b1dc(n));
                    c0 = in->h0;
                    c1 = in->h1;
                    c2 = in->h2;
                    c3 = in->h3;
                    v = FUN_0016b19c(n);
                }
            }
            Entry *e = Get(n);
            Info *in = FUN_0016b3d8(n, FUN_0016b1dc(n));
            FObj *fo = FUN_0016b21c(n);
            int fl = DAT_003415a8->flags.Get(n);
            FUN_001c1c50(2, FUN_001fea10(12, 0, n), n, c0, c1, c2, c3, v, in->x9 != 0, in->xa != 0, in->x8 != 0, h,
                         FUN_0016bb5c(), FUN_0016bb98(n, &e->sub), n, &e->sub, fl, 0, 0,
                         FUN_0024dd40(fo->f4, DAT_0034a77c), 1, 0, 0, 0, e);
        }
        break;
    }
    switch (p->x28) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        HST_ASSERT(pNpc1, ASSERT_STR1, 2129);
        FUN_001c1c50(1, FUN_001feac4(pNpc1->xe, pNpc1->x20), pNpc1->id, pNpc1->x2, pNpc1->x4, pNpc1->x6, pNpc1->x8, pNpc1->xa, 0, 0, 0,
                     pNpc1->tri[mode].c, pNpc1->tri[mode].a, FUN_0016bb98(pNpc1->id, &pNpc1->sub), pNpc1->x78, &pNpc1->sub, pNpc1->x7c,
                     0, 0, pNpc1->tri[mode].b, 1, 0, 0, 0, *(Entry *volatile *)&pNpc1);
        break;
    }
    switch (p->x28) {
    case 1:
    case 3:
    case 5:
        HST_ASSERT(pNpc2, ASSERT_STR2, 2171);
        FUN_001c1c50(3, FUN_001feac4(pNpc2->xe, pNpc2->x20), pNpc2->id, pNpc2->x2, pNpc2->x4, pNpc2->x6, pNpc2->x8, pNpc2->xa, 0, 0, 0,
                     pNpc2->tri[mode].c, pNpc2->tri[mode].a, FUN_0016bb98(pNpc2->id, &pNpc2->sub), pNpc2->x78, &pNpc2->sub, pNpc2->x7c,
                     0, 0, pNpc2->tri[mode].b, 1, 0, 0, 0, *(Entry *volatile *)&pNpc2);
        break;
    }
    FUN_001c19e4(FUN_0016b118(), h, lvl, b27, 0);
    int g = DAT_0031101c;
    FUN_001c1d0c(g, g + 1, g + 2, g + 3, g + 4);
}
// NEAR MISS (4 words): only the branch-likely choice differs at the default-index search.
// Retail: outer `if ((short)idx == 0)` branch is `bnez v0,join; nop` and the inner `if (!found) idx = 1;`
// branch is `bnezl s7,join+4; lh v1,36(s4)`; ours converts the OUTER branch to the likely form instead
// (one likely copy per target block). Ruled out (all still 4 words): `!(short)idx`, `(short)idx != 0 {} else`,
// int/char found, found declared outside the if, found = true/idx = i order, while/continue loop forms,
// `if (found) {} else`, `found == false` (worse), goto/label/do-while(0)/switch wrappers, empty else,
// the search as an inline (bool Find(int&), int Search(), void Search(int&), whole-if Pick/Pick2),
// && form `(short)idx == 0 && !Find(idx)`, x24 test as if/else, inline normalisation helpers.
// The `*(Entry *volatile *)&pNpc` last arguments reproduce retail's reload of the local after the nested
// calls (a plain pNpc1/pNpc2 is CSE'd into s0; tried local copy, reference, Ref wrapper, array, struct
// by value (lwc1 copy), split statements (moves mode*3 after the call), inline name helper, real asserts).
