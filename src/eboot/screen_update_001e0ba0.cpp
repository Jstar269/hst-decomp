/* HSTMATCH module=EBOOT.BIN start=0x001e0ba0 end=0x001e1084 symbol=FUN_001e0ba0 lang=c++ data=0x002ebb34 */
/* Hand-written reconstruction from the disassembly (structured after the hstgen.py tag a7 candidate's Ghidra pseudocode); exact match verified; names and types await human review. */
/* Per-frame update of a screen object: each optional part (a virtual-call object at +0x3c.. and the 0x8c-byte sub-objects updated by 0x217940 beside it) is updated when present; two pulse counters (+0x28b4/+0x28b8) and one (+0x2354) step a 5-entry grey table (0x80,0xc0,0xff,0xc0,0x80; anonymous .data at 0x2ebb34, local copy loop) into colour words; the countdown at +0x2528 calls 0x1e7cf0 when it runs out. Matching idioms: the first guard is a one-case `switch (s->f44) { case 0: ... }` (an `if (f44 == 0)` lays the block out with bnezl and without retail's `beqzl ...; b` pair and its unfilled inner slot); the table is a local `const unsigned char tab[5]` initialiser; `Gray(c)` = (c << 24) | (c << 16) | (c << 8) | c; the third counter block re-reads tab[0] when the decremented value is 0. Names provisional. */
struct VObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
};
struct Anim {
    char pad0[0x3d];
    unsigned char f3d;
    char pad3e[0x4e];
};
struct Color;
struct Slot {
    Color *c;
    char pad[0x10];
};
struct Screen {
    char pad0[0x3c];
    VObj * p3c;
    VObj * p40;
    int f44;
    Anim a48;
    VObj * pd4;
    char padd8[0x90];
    Anim a168;
    VObj * p1f4;
    char pad1f8[0x78];
    void * p270;
    char pad274[0x138];
    Anim a3ac;
    char pad438[0x4];
    Anim a43c;
    Anim a4c8;
    Anim a554;
    Anim a5e0;
    Anim a66c;
    Anim a6f8;
    Anim a784;
    VObj * p810;
    char pad814[0x88];
    Anim a89c;
    Anim a928;
    VObj * p9b4;
    char pad9b8[0xda4];
    VObj * p175c;
    char pad1760[0xdc];
    Anim a183c;
    Anim a18c8;
    VObj * p1954;
    VObj * p1958;
    char pad195c[0x1d8];
    Anim a1b34;
    Anim a1bc0;
    Anim a1c4c;
    Anim a1cd8;
    VObj * p1d64;
    VObj * p1d68;
    char pad1d6c[0x1bc];
    Anim a1f28;
    Anim a1fb4;
    Anim a2040;
    Anim a20cc;
    Anim a2158;
    VObj * p21e4;
    char pad21e8[0x4];
    Slot slotsA[1];
    char pad2200[0xc4];
    Anim a22c4;
    int n2350;
    int n2354;
    char pad2358[0x4];
    VObj * p235c;
    char pad2360[0x4];
    Slot slotsB[1];
    char pad2378[0xec];
    VObj * p2464;
    char pad2468[0x18];
    Anim a2480;
    VObj * p250c;
    char pad2510[0x18];
    int n2528;
    Anim a252c;
    VObj * p25b8;
    char pad25bc[0x28];
    Color * c25e4;
    char pad25e8[0x10];
    Color * c25f8;
    char pad25fc[0x1a0];
    Anim a279c;
    Anim a2828;
    int n28b4;
    int n28b8;
};
extern "C" {
void FUN_00217940(Anim *);
void FUN_002178d4(Anim *);
void FUN_000ffb3c(void *, int);
void FUN_000ffc70(Color *, unsigned);
void FUN_001e7cf0(Screen *);
}
static inline unsigned Gray(unsigned c)
{
    return (c << 24) | (c << 16) | (c << 8) | c;
}
extern "C" void FUN_001e0ba0(Screen *s)
{
    const unsigned char tab[5] = { 0x80, 0xc0, 0xff, 0xc0, 0x80 };
    switch (s->f44) {
    case 0:
        FUN_00217940(&s->a48);
        s->p40->s2();
        if (s->pd4 != 0) {
            FUN_00217940(&s->a168);
            s->pd4->s2();
        }
        break;
    }
    if (s->p3c != 0)
        s->p3c->s2();
    if (s->p25b8 != 0) {
        FUN_00217940(&s->a279c);
        FUN_00217940(&s->a2828);
        s->p25b8->s2();
        if (s->n28b4 > 0) {
            unsigned u = --s->n28b4;
            FUN_000ffc70(s->c25f8, Gray(tab[u % 5]));
        }
        if (s->n28b8 > 0) {
            unsigned u = --s->n28b8;
            FUN_000ffc70(s->c25e4, Gray(tab[u % 5]));
        }
    }
    if (s->p1f4 != 0) {
        FUN_00217940(&s->a3ac);
        FUN_00217940(&s->a43c);
        FUN_00217940(&s->a4c8);
        FUN_00217940(&s->a554);
        FUN_00217940(&s->a5e0);
        FUN_00217940(&s->a66c);
        if (s->a66c.f3d != 0) {
            FUN_002178d4(&s->a66c);
            FUN_000ffb3c(s->p270, 1);
        }
        FUN_00217940(&s->a6f8);
        FUN_00217940(&s->a784);
        s->p1f4->s2();
    }
    if (s->p9b4 != 0)
        s->p9b4->s2();
    if (s->p810 != 0) {
        FUN_00217940(&s->a89c);
        FUN_00217940(&s->a928);
        s->p810->s2();
    }
    if (s->p175c != 0) {
        FUN_00217940(&s->a183c);
        FUN_00217940(&s->a18c8);
        s->p175c->s2();
    }
    if (s->p1954 != 0)
        s->p1954->s2();
    if (s->p1d68 != 0) {
        FUN_00217940(&s->a1f28);
        FUN_00217940(&s->a1fb4);
        FUN_00217940(&s->a2040);
        FUN_00217940(&s->a20cc);
        FUN_00217940(&s->a2158);
        s->p1d68->s2();
    }
    if (s->p1958 != 0) {
        FUN_00217940(&s->a1b34);
        FUN_00217940(&s->a1c4c);
        FUN_00217940(&s->a1bc0);
        FUN_00217940(&s->a1cd8);
        s->p1958->s2();
        if (s->p1d64 != 0)
            s->p1d64->s2();
    }
    bool b = false;
    if (s->p21e4 != 0) {
        FUN_00217940(&s->a22c4);
        s->p21e4->s2();
        if (s->n2354 > 0) {
            unsigned u = --s->n2354;
            unsigned char c = tab[u % 5];
            if (u == 0)
                c = tab[0];
            FUN_000ffc70(s->slotsA[s->n2350].c, Gray(c));
        }
        b = true;
    }
    if (s->p235c != 0) {
        FUN_00217940(&s->a22c4);
        s->p235c->s2();
        if (s->n2354 > 0 && !b) {
            unsigned u = --s->n2354;
            unsigned char c = tab[u % 5];
            if (u == 0)
                c = tab[0];
            FUN_000ffc70(s->slotsB[s->n2350].c, Gray(c));
        }
    }
    if (s->p2464 != 0) {
        FUN_00217940(&s->a2480);
        s->p2464->s2();
    }
    if (s->p250c != 0) {
        FUN_00217940(&s->a252c);
        s->p250c->s2();
        if (s->n2528 > 0 && --s->n2528 < 1) {
            s->n2528 = 0;
            FUN_001e7cf0(s);
        }
    }
}
