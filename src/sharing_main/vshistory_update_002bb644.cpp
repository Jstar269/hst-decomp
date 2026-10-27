/* HSTMATCH module=hstp_trans_main.prx start=0x002bb644 end=0x002bc2e8 symbol=FUN_002bb644 lang=c++ */
/* Clone of src/eboot/vshistory_update_002abe88.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the f58 branch is an inline Save() helper (its unfilled `b; nop` tail), the duplicated close-out sequence is the inline CloseEntry(), the f59 arm is wrapped as `if (DAT_003eaab1 == 0) {..} return;` (the trailing return puts MWCC's branch cleanup into the mode that keeps retail's dead delay-slot originals), the saved pad bit is read through an `int` getter into a `char` local (retail's seb), and the two Vec4 records are const& temporaries; StrPair is the same 24-byte string pair class as 0x2abb70; names and types await human review. */
struct Str {
    unsigned cap;
    unsigned size;
    char *data;
    const char *c_str() const { return (cap & 1) ? data : (const char *)this + 1; }
};

struct Rep {
    int a, b, c;
};

extern "C" {
Str *FUN_000031f0(Str *, const char *);
void FUN_00003e04(Str *, const Str *);
void FUN_00004138(Str *, int);
void FUN_0019d090(Rep *, const Rep *);
void FUN_000463a0(Rep *, int);
}

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
        FUN_000463a0(&r, -1);
        FUN_00004138(&s, 0);
    }
    StrPair &operator=(const StrPair &o)
    {
        FUN_00003e04(&s, &o.s);
        FUN_0019d090(&r, &o.r);
        return *this;
    }
};

struct VC {
    virtual void m0();
    virtual void m1(bool);
    virtual void m2();
};

struct Box {
    char pad0[0xf8];
    char *ff8;
    char padfc[0x138 - 0xfc];
    int f138;
};

struct VA : VC {
};

struct Menu : VC {
    char pad4[0xdc - 4];
    int fdc;
};

struct VB : VC {
    char pad4[0x170 - 4];
    Box *f170;
    Box *f174;
    Menu *f178;
    unsigned char f17c;
    char pad17d[0x77d - 0x17d];
    char f77d[0x80];
    char f7fd[0x87];
    int f884;
};

struct VCc {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    char pad4[0x358 - 4];
    VC *f358;
    int pad35c;
    unsigned char f360;
    char pad361[0x1668 - 0x361];
    int f1668;
    int f166c;
};

struct Ent12 {
    int v;
    int pad[2];
};

struct VD : VC {
    char pad4[0x30c4 - 4];
    bool f30c4;
    bool f30c5;
    char pad30c6[0x30f0 - 0x30c6];
    Ent12 tbl[2];
    bool NotFlag() { return !f30c4; }
};

struct Info {
    char pad0[0x1c];
    int f1c;
    void *f20;
    char pad24[0x2c - 0x24];
    int f2c;
    int f30;
};

struct Ent {
    char pad0[0x70];
    Info *p70;
};

struct Self {
    char pad0[0x3c];
    VA *f3c;
    VB *f40;
    VCc *f44;
    VD *f48;
    int mode;
    int f50;
    int f54;
    unsigned char f58;
    unsigned char f59;
    unsigned char f5a;
    StrPair p5c;
    StrPair p74;
    Ent *f8c;
    unsigned short f90[150];
    void Set54(int v)
    {
        if (v != f54)
            f54 = v;
    }
};

struct Btn {
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
    signed char d : 2;
    int C() const { return c; }
};

struct Pad {
    char pad0[0x88];
    Btn k88;
    Btn k89;
    Btn k8a;
    Btn k8b;
};

struct Glob {
    char pad0[0xc];
    int fc;
    char pad10[0x52 - 0x10];
    unsigned char f52;
};

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

extern "C" {
extern Pad *DAT_003751d4;
extern int DAT_003a9b90[];
extern char DAT_003abd2c[];
extern Glob *DAT_003daec4;
extern char DAT_003eaad8[];
extern char *DAT_003ea8e8;
extern void *DAT_003ea8ec;
extern unsigned char DAT_003eaab1;
extern char DAT_003f39a8[];
extern void *DAT_003f46a0;
StrPair FUN_00045830(const unsigned short *);
int FUN_0004587c(StrPair *);
void FUN_00011090(unsigned short *, int, int);
void FUN_000143b0(char *, const char *, const char *);
void FUN_00014a40(const char *);
void FUN_000646f4(float, float, Glob *, const Vec4 &, const Vec4 &, int, int, int);
void FUN_00108f54(void *, int);
void FUN_00111aa4(VC *, int, int);
void FUN_00113a50(Box *);
void FUN_0011988c(void *, const char *, int);
void FUN_0011e940(void *, int, const char *, int, int);
int FUN_001204dc(void *);
int FUN_001205f0(void *);
void FUN_001a5d3c(Ent *);
void FUN_001bfc3c(char *, int);
void FUN_001c20b8(char *);
const char *FUN_0020d1e0(int, int, int);
void FUN_0024476c(char *);
void FUN_002b497c(const char *, char *, char *);
void FUN_002b4f7c(VA *, int, int);
void FUN_002b55cc(VB *, int);
void FUN_002b69a8(VCc *, int);
void FUN_002b88d0(VD *, int, int);
void FUN_002b8b2c(VD *, bool, int);
void FUN_002bb0b8(Self *, int);
void FUN_002bb32c(Self *, int);
const char *FUN_002be958(char *);
void FUN_002beaa8(char *, const char *);
int FUN_002beb30(char *);
void FUN_002beba0(char *, int);
}

static inline void CloseEntry(Self *self)
{
    self->f59 = 0;
    VB *b = self->f40;
    b->f178->m1(0);
    b->f17c = 1;
    int v = b->f178->fdc;
    FUN_00111aa4(b->f178, v, 0);
    if (DAT_003f46a0 != 0)
        FUN_0011988c(DAT_003f46a0, FUN_0020d1e0(18, 49, DAT_003a9b90[v]), 0);
}

static inline void Save(Self *self)
{
    if (FUN_001204dc(DAT_003ea8ec) == 0)
        return;
    FUN_00108f54(DAT_003ea8ec, 1);
    if (FUN_001205f0(DAT_003ea8ec) == 0) {
        VCc *c = self->f44;
        FUN_002beba0(DAT_003ea8e8 + 0x87128, c->f1668 + c->f166c);
        c->m1();
    }
    self->f58 = 0;
    VCc *c = self->f44;
    bool ok = 0 < FUN_002beb30(DAT_003ea8e8 + 0x87128);
    c->f358->m1(!ok);
    c->f360 = 1;
}

extern "C" void FUN_002bb644(Self *self)
{
    int cur = self->f50;
    if (self->f58 != 0) {
        Save(self);
        return;
    }
    if (self->f59 != 0) {
        if (DAT_003eaab1 == 0) {
            if (self->f8c->p70->f2c != 2) {
                CloseEntry(self);
            } else {
                char buf[256];
                self->p5c = FUN_00045830(self->f90);
                FUN_000143b0(buf, DAT_003abd2c, self->p5c.s.c_str());
                FUN_00014a40(self->p5c.s.c_str());
                self->p5c = StrPair(buf);
                const char *name = self->p5c.s.c_str();
                VB *b = self->f40;
                FUN_002beaa8(DAT_003ea8e8 + 0x87128, name);
                FUN_002b497c(name, b->f77d, b->f7fd);
                Box *x = b->f170;
                x->ff8 = b->f77d;
                x->f138 = 1;
                FUN_00113a50(x);
                x = b->f174;
                x->ff8 = b->f7fd;
                x->f138 = 1;
                FUN_00113a50(x);
                CloseEntry(self);
            }
            Glob *g = DAT_003daec4;
            g->fc = 0;
            g->f52 = 0;
            FUN_00108f54(DAT_003f46a0, 0);
        }
        return;
    }
    if (DAT_003751d4->k88.a != 0) {
        char c = DAT_003751d4->k8b.C();
        if (c == 0 && !(self->mode == 2 && self->f54 == 1) && !(self->mode == 3 && self->f48->f30c5 != 0)
            && !(self->mode == 4 && self->f48->f30c5 != 0)) {
            if (self->f5a != 0) {
                FUN_001c20b8(DAT_003eaad8);
                FUN_001bfc3c(DAT_003eaad8, 4);
                FUN_0024476c(DAT_003f39a8);
            } else {
                FUN_002bb0b8(self, 1);
                FUN_001bfc3c(DAT_003eaad8, 4);
            }
        } else if (DAT_003751d4->k8a.a == 0 && self->mode != 0) {
            self->f50 = (cur + 3) % 4;
        } else if (DAT_003751d4->k8a.b == 0 && self->mode != 0) {
            self->f50 = (cur + 1) % 4;
        } else if (self->f5a != 0) {
            if (DAT_003751d4->k89.d == 0 && self->mode != 0) {
                self->f50 = (cur + 3) % 4;
            } else if (DAT_003751d4->k89.b == 0 && self->mode != 0) {
                self->f50 = (cur + 1) % 4;
            } else if (DAT_003751d4->k8b.b == 0) {
                if ((self->mode != 2 || FUN_002beb30(DAT_003ea8e8 + 0x87128) > 0)
                    && (self->mode != 3 || self->f48->tbl[self->f48->NotFlag()].v > 0)
                           && (self->mode != 4 || self->f48->tbl[self->f48->NotFlag()].v > 0)) {
                    FUN_002bb0b8(self, 0);
                    FUN_001bfc3c(DAT_003eaad8, 3);
                }
            }
        } else {
            switch (self->mode) {
            case 1:
                if (DAT_003751d4->k8b.a == 0) {
                    self->Set54((self->f54 + 1) % 2);
                    FUN_002b55cc(self->f40, self->f54);
                    FUN_001bfc3c(DAT_003eaad8, 6);
                } else if (DAT_003751d4->k8b.b == 0 && self->f59 == 0 && self->f40->f884 == 13) {
                    self->p5c = StrPair(FUN_002be958(DAT_003ea8e8 + 0x87128));
                    FUN_00011090(self->f90, FUN_0004587c(&self->p5c), 150);
                    self->p74 = StrPair(FUN_0020d1e0(17, 13, 3));
                    self->f8c->p70->f1c = FUN_0004587c(&self->p74);
                    self->f8c->p70->f20 = self->f90;
                    FUN_001a5d3c(self->f8c);
                    self->f8c->p70->f30 = 24;
                    VB *b = self->f40;
                    b->f178->m1(1);
                    b->f17c = 0;
                    self->f59 = 1;
                    FUN_001bfc3c(DAT_003eaad8, 3);
                    FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, Vec4(0.0f, 0.0f, 0.0f, 0.0f), Vec4(0.0f, 0.0f, 0.0f, 0.75f), 1, 0, 0);
                    FUN_00108f54(DAT_003f46a0, 1);
                }
                break;
            case 2:
                if (FUN_002beb30(DAT_003ea8e8 + 0x87128) > 0) {
                    if (DAT_003751d4->k8b.b == 0) {
                        if (self->f54 == 0) {
                            self->Set54(1);
                            FUN_002b69a8(self->f44, self->f54);
                            FUN_002b4f7c(self->f3c, self->mode - 1, self->f54);
                            FUN_001bfc3c(DAT_003eaad8, 3);
                        }
                    } else if (DAT_003751d4->k8b.c == 0) {
                        if (self->f54 == 1) {
                            self->Set54(0);
                            FUN_002b69a8(self->f44, self->f54);
                            FUN_002b4f7c(self->f3c, self->mode - 1, self->f54);
                            FUN_001bfc3c(DAT_003eaad8, 4);
                        }
                    } else if (DAT_003751d4->k8b.d == 0 && self->f54 == 0) {
                        FUN_0011e940(DAT_003ea8ec, 1, FUN_0020d1e0(17, 19, 0), 0, 0);
                        self->f58 = 1;
                        VCc *cc = self->f44;
                        cc->f358->m1(1);
                        cc->f360 = 0;
                        FUN_001bfc3c(DAT_003eaad8, 3);
                    }
                }
                break;
            case 3:
            case 4:
                if (self->f48->tbl[self->f48->NotFlag()].v > 0) {
                    if (DAT_003751d4->k8b.a == 0) {
                        self->Set54((self->f54 + 1) % 3);
                        FUN_002b88d0(self->f48, self->f54, 0);
                        FUN_002b8b2c(self->f48, self->f48->f30c5, 1);
                        FUN_001bfc3c(DAT_003eaad8, 6);
                    } else if (c == 0) {
                        FUN_002b8b2c(self->f48, 0, 1);
                        FUN_002b4f7c(self->f3c, self->mode - 1, self->f48->f30c5);
                        FUN_002bb0b8(self, 1);
                        FUN_001bfc3c(DAT_003eaad8, 4);
                    } else if (DAT_003751d4->k8b.d == 0) {
                        FUN_002b8b2c(self->f48, !self->f48->f30c5, 1);
                        FUN_002b4f7c(self->f3c, self->mode - 1, self->f48->f30c5);
                        FUN_001bfc3c(DAT_003eaad8, 1);
                    }
                }
                break;
            }
        }
    }
    if (cur != self->f50) {
        FUN_002bb32c(self, self->f50 + 1);
        FUN_002bb0b8(self, 1);
        FUN_001bfc3c(DAT_003eaad8, 6);
    }
    self->f3c->m2();
    switch (self->mode) {
    case 1:
        self->f40->m2();
        break;
    case 2:
        self->f44->m2();
        break;
    case 3:
        self->f48->m2();
        break;
    case 4:
        self->f48->m2();
        break;
    }
}
