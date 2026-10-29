/* HSTMATCH module=EBOOT.BIN start=0x0022d848 end=0x0022da30 symbol=FUN_0022d848 lang=c++ */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
/* Matching idiom: the 12-byte second part of a temporary is zeroed through an int pointer (`int *p = &r.a; p[0..2] = 0`);
   direct member stores, an array member, an inline Clear() member or a member-init list schedule the stores after the
   argument set-up of the following assignment call. */
struct Str {
    char d[12];
};

struct Rep {
    int a, b, c;
};

extern "C" {
Str *FUN_000031f0(Str *, const char *);
void FUN_00003e04(Str *, const Str *);
void FUN_00004138(Str *, int);
void FUN_00190880(Rep *, const Rep *);
void FUN_000462a0(Rep *, int);
int FUN_0004577c(Str *);
void FUN_00103628(void *, int);
int FUN_00190830(void *);
void FUN_00199244(int);
const char *FUN_001fea10(int, int, int);
extern void *DAT_003415ac;
extern char *DAT_003415a8;
extern void *DAT_003415d4;
extern char DAT_002f3538;
}

/* A string (12 bytes) followed by a second 12-byte string-like part, with the out-of-line assignment/destructor helpers. */
struct StrPair {
    Str s;
    Rep r;
    StrPair(const char *lit)
    {
        FUN_000031f0(&s, lit);
        int *p = &r.a;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
    }
    ~StrPair()
    {
        FUN_000462a0(&r, -1);
        FUN_00004138(&s, 0);
    }
    StrPair &operator=(const StrPair &o)
    {
        FUN_00003e04(&s, &o.s);
        FUN_00190880(&r, &o.r);
        return *this;
    }
};

struct VC {
    virtual void s0();
    virtual void s1(int);
};

/* Record handed to FUN_00199244; its sub-record at 0x70 receives two string lengths. */
struct Ent {
    char pad[0x70];
    struct {
        char pad[0x1c];
        int len1c;
        int len20;
    } *sub70;
};

struct PairScreen {
    char pad0[0x58];
    StrPair pair58;   /* 0x58 */
    StrPair pair70;   /* 0x70 */
    StrPair pair88;   /* 0x88 */
    char pad1[0x210 - 0xa0];
    VC *view210;      /* 0x210 */
    void *obj214;     /* 0x214 */
};

/* Resets the screen's string pairs to blank and (optionally) the setup string, then stores the lengths of two of them in the entry. */
extern "C" void FUN_0022d848(PairScreen *o, int set_first)
{
    FUN_00103628(DAT_003415ac, 1);
    o->pair70 = StrPair(&DAT_002f3538);
    o->pair88 = StrPair(&DAT_002f3538);
    Ent *ent = (Ent *)FUN_00190830(DAT_003415d4);
    if (set_first != 0) {
        o->pair58 = StrPair(DAT_003415a8 + 0x20);
    }
    o->pair88 = StrPair(FUN_001fea10(0x11, 0xd, 2));
    ent->sub70->len1c = FUN_0004577c(&o->pair88.s);
    ent->sub70->len20 = FUN_0004577c(&o->pair58.s);
    FUN_00199244((int)ent);
    o->view210->s1(1);
    if (o->obj214 != 0) {
        FUN_00103628(o->obj214, 1);
    }
}
