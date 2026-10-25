/* HSTMATCH module=EBOOT.BIN start=0x00194ba4 end=0x00194e20 symbol=FUN_00194ba4 lang=c++ */
struct Row {
    char p0;
    unsigned char b1;
    unsigned short s2;
};

struct Cell {
    unsigned short a, b, c, d;
    unsigned char e, f, g, h;
};

struct Info {
    char pad[0xc];
    unsigned char c, d;
};

struct Table {
    unsigned count;
    Info *recs;
};

struct Flags {
    char pad[0x1025];
    char f[15];
};

struct Globals {
    char pad[0x80];
    Flags flags;
};

struct Rec {
    int id;
    unsigned a, b, c, d, e;
    Rec(int i) : id(i), a(0x7fffffff), b(0x7fffffff), c(0x7fffffff), d(0x7fffffff), e(0x7fffffff) {}
};

extern "C" {
extern char *DAT_00341ccc;
extern Table *DAT_00341744;
extern Globals *DAT_003415a8;
void FUN_00092c38(int a, int b);
void FUN_00204c88(int a, unsigned char *p1, unsigned char *p2, unsigned char *p3, Rec *r, int t1, int t2, int t3, int s0, int s1, int s2);
void FUN_00092630(int a, int b);
}

static inline Row *GetRow(int i)
{
    char *base = DAT_00341ccc;
    if (i >= 0 && i < 15) {
        return (Row *)(base + i * 0x38 + 4);
    }
    return 0;
}

static inline Cell *GetCell(short row, short col)
{
    char *base = DAT_00341ccc;
    if (row >= 0 && row < 15 && col >= 0 && col < 4) {
        return (Cell *)(base + row * 0x38 + col * 0xc + 0xc);
    }
    return 0;
}

static inline Info *GetInfo(short i)
{
    Table *t = DAT_00341744;
    if (t == 0) {
        return 0;
    }
    if (i < 0 || (unsigned)i >= t->count) {
        return 0;
    }
    return &t->recs[i];
}

static inline char GetFlag(int i)
{
    if (i < 0) {
        return 1;
    }
    if (i < 15) {
        return DAT_003415a8->flags.f[i];
    }
    return 1;
}

extern "C" void FUN_00194ba4(int self, unsigned short idx, unsigned mask)
{
    for (int i = 0; i < 6; i++) {
        FUN_00092c38(self, i);
    }
    unsigned char l1 = 0;
    unsigned char l2 = 0;
    unsigned char l3 = 0;
    short sidx = (short)idx;
    Row *row = GetRow((unsigned short)sidx);
    Cell *cell = GetCell(sidx, (short)(unsigned short)row->b1);
    Info *info = GetInfo(sidx);
    Rec rec(sidx);
    rec.a = cell->a;
    rec.b = cell->b;
    if ((mask & 8) == 0) {
        rec.c = cell->c;
    }
    if ((mask & 0x10) == 0) {
        rec.d = cell->d;
    }
    if ((mask & 0x20) == 0) {
        rec.e = GetRow((unsigned short)idx)->s2;
    }
    FUN_00204c88(self, &l2, &l1, &l3, &rec, cell->f != 0, cell->g != 0, GetFlag(rec.id) == 2, info->d, info->c, 0);
    FUN_00092630(self, cell->e != 0);
}
// NEAR 0x00194ba4: 158/159 words, 124 differ (mostly register renaming: structure, branches, frame 80, all stores and the FUN_00204c88 11-argument call are in retail order).
// Differs: s-register assignment (retail self=s2, idx=s3, mask=s1, i=s0; ours self=s3, idx=s2) and temp colours: retail loads the table base into a0 BEFORE `seh v0,idx` and keeps it for all three accessors; ours puts it in v1.
// Idioms found: three inline bounds accessors (GetRow int idx with `i >= 0 && i < 15`, GetCell(short,short), GetInfo(short) with the unsigned count compare, GetFlag through a Globals struct whose sub-object sits at +0x80) each reading `char *base = DAT_00341ccc` first so the load is shared; the bltz on the unsigned-short index is kept because the accessor takes a plain int; Rec ctor writes id then five 0x7fffffff.
// Ruled out: short vs unsigned short parameter, local short/unsigned copies of idx, (unsigned short)(short) cast chains (fold the bltz away), accessor taking short and converting inside.
// near miss from lane sn8 (unreviewed)
