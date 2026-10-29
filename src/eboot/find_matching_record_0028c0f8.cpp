/* HSTMATCH module=EBOOT.BIN start=0x0028c0f8 end=0x0028c204 symbol=FUN_0028c0f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the config constants (g->fcc + 1, g->fd0 + 1) and the end pointer are read into locals before the loop; spelled inside the loop condition they are not hoisted (73 words). The empty Tag passed by value to AtEnd gives retail's 16-byte frame slot. */

struct Rec {
    int f0;
    int f4;
    int f8;
    int fc;
    char pad0[0x47 - 0x10];
    char name[0x60 - 0x47];
};

struct Vec {
    Rec *beg;
    int count;
};

struct Cfg {
    char pad[0xcc];
    int fcc;
    int fd0;
};

struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(int, int);
    char pad0[0x30 - 4];
    int f30;
    int f34;
};

struct Tag {};

static inline bool AtEnd(Rec *p, Rec *end, Tag)
{
    return !(p == end);
}

extern "C" Cfg *DAT_0034a114;
extern "C" char DAT_0034179c;
extern "C" int FUN_00014a40(char *s);
extern "C" void FUN_001b28f0(const char *fmt, char *s);

extern "C" void FUN_0028c0f8(Vec *v, Obj *o, int arg)
{
    if (o != 0)
        o->m8(arg, 0);
    Cfg *g = DAT_0034a114;
    int c0 = g->fcc + 1;
    int c1 = g->fd0 + 1;
    Rec *p = v->beg;
    Rec *end = v->beg + v->count;
    while (AtEnd(p, end, Tag())) {
        if (p->f0 == c0 && p->f4 == c1 && p->fc == o->f30 && p->f8 == o->f34) {
            if (FUN_00014a40(p->name) != 0)
                FUN_001b28f0(&DAT_0034179c, p->name);
            break;
        }
        p++;
    }
}
