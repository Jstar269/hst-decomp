/* HSTMATCH module=EBOOT.BIN start=0x0028c0f8 end=0x0028c204 symbol=FUN_0028c0f8 lang=c++ */
// NEAR MISS (73/67 words, 42 differ, first at +0x38): with the tag-by-value inline loop test the frame,
// the virtual call, the config-global load and the first 20 words are in place, and the whole match
// block (four field compares, the string check and the log call) is structurally right. The remaining
// gap is the colouring of the two config constants: retail computes `g->fcc + 1` into a3 (in the delay
// area between the two field loads) and `g->fd0 + 1` into a2, ours produces a0/v1 and also swaps the
// end-pointer/bool registers. Ruled out: locals for the two constants declared in either order, an
// `int`-returning instead of `bool`-returning helper (adds an andi), and `p != end` inside the helper
// (gives sltu zero,v instead of the xor/sltiu/xori chain).

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
    Rec *p;
    int c0;
    int c1;

    if (o != 0)
        o->m8(arg, 0);
    p = v->beg;
    while (AtEnd(p, v->beg + v->count, Tag())) {
        if (p->f0 == DAT_0034a114->fcc + 1 && p->f4 == DAT_0034a114->fd0 + 1 && p->fc == o->f30 && p->f8 == o->f34) {
            if (FUN_00014a40(p->name) != 0)
                FUN_001b28f0(&DAT_0034179c, p->name);
            break;
        }
        p++;
    }
}
// near miss from lane ds1 (unreviewed)
