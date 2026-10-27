/* HSTMATCH module=EBOOT.BIN start=0x002abe88 end=0x002acb2c symbol=FUN_002abe88 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the f58 branch is an inline Save() helper (its unfilled `b; nop` tail), the duplicated close-out sequence is the inline CloseEntry(), the f59 arm is wrapped as `if (DAT_00341771 == 0) {..} return;` (the trailing return puts MWCC's branch cleanup into the mode that keeps retail's dead delay-slot originals), the saved pad bit is read through an `int` getter into a `char` local (retail's seb), and the two Vec4 records are const& temporaries; StrPair is the same 24-byte string pair class as 0x2abb70; names and types await human review. */
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
void FUN_00190880(Rep *, const Rep *);
void FUN_000462a0(Rep *, int);
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
extern Pad *DAT_002cfc8c;
extern int DAT_00300af4[];
extern char DAT_00302c50[];
extern Glob *DAT_00331b84;
extern char DAT_0034179c[];
extern char *DAT_003415a8;
extern void *DAT_003415ac;
extern unsigned char DAT_00341771;
extern char DAT_0034a678[];
extern void *DAT_0034b354;
StrPair FUN_00045730(const unsigned short *);
int FUN_0004577c(StrPair *);
void FUN_00011090(unsigned short *, int, int);
void FUN_000143b0(char *, const char *, const char *);
void FUN_00014a40(const char *);
void FUN_00063830(float, float, Glob *, const Vec4 &, const Vec4 &, int, int, int);
void FUN_00103628(void *, int);
void FUN_0010b8cc(VC *, int, int);
void FUN_0010d4a8(Box *);
void FUN_00110a78(void *, const char *, int);
void FUN_00114168(void *, int, const char *, int, int);
int FUN_001155c0(void *);
int FUN_001156d4(void *);
void FUN_00199244(Ent *);
void FUN_001b1c44(char *, int);
void FUN_001b3e2c(char *);
const char *FUN_001fea10(int, int, int);
void FUN_0023466c(char *);
void FUN_002a51ec(const char *, char *, char *);
void FUN_002a57ec(VA *, int, int);
void FUN_002a5e3c(VB *, int);
void FUN_002a7218(VCc *, int);
void FUN_002a9114(VD *, int, int);
void FUN_002a9370(VD *, bool, int);
void FUN_002ab8fc(Self *, int);
void FUN_002abb70(Self *, int);
const char *FUN_002af0d4(char *);
void FUN_002af224(char *, const char *);
int FUN_002af274(char *);
void FUN_002af29c(char *, int);
}

static inline void CloseEntry(Self *self)
{
    self->f59 = 0;
    VB *b = self->f40;
    b->f178->m1(0);
    b->f17c = 1;
    int v = b->f178->fdc;
    FUN_0010b8cc(b->f178, v, 0);
    if (DAT_0034b354 != 0)
        FUN_00110a78(DAT_0034b354, FUN_001fea10(18, 49, DAT_00300af4[v]), 0);
}

static inline void Save(Self *self)
{
    if (FUN_001155c0(DAT_003415ac) == 0)
        return;
    FUN_00103628(DAT_003415ac, 1);
    if (FUN_001156d4(DAT_003415ac) == 0) {
        VCc *c = self->f44;
        FUN_002af29c(DAT_003415a8 + 0x87128, c->f1668 + c->f166c);
        c->m1();
    }
    self->f58 = 0;
    VCc *c = self->f44;
    bool ok = 0 < FUN_002af274(DAT_003415a8 + 0x87128);
    c->f358->m1(!ok);
    c->f360 = 1;
}

extern "C" void FUN_002abe88(Self *self)
{
    int cur = self->f50;
    if (self->f58 != 0) {
        Save(self);
        return;
    }
    if (self->f59 != 0) {
        if (DAT_00341771 == 0) {
            if (self->f8c->p70->f2c != 2) {
                CloseEntry(self);
            } else {
                char buf[256];
                self->p5c = FUN_00045730(self->f90);
                FUN_000143b0(buf, DAT_00302c50, self->p5c.s.c_str());
                FUN_00014a40(self->p5c.s.c_str());
                self->p5c = StrPair(buf);
                const char *name = self->p5c.s.c_str();
                VB *b = self->f40;
                FUN_002af224(DAT_003415a8 + 0x87128, name);
                FUN_002a51ec(name, b->f77d, b->f7fd);
                Box *x = b->f170;
                x->ff8 = b->f77d;
                x->f138 = 1;
                FUN_0010d4a8(x);
                x = b->f174;
                x->ff8 = b->f7fd;
                x->f138 = 1;
                FUN_0010d4a8(x);
                CloseEntry(self);
            }
            Glob *g = DAT_00331b84;
            g->fc = 0;
            g->f52 = 0;
            FUN_00103628(DAT_0034b354, 0);
        }
        return;
    }
    if (DAT_002cfc8c->k88.a != 0) {
        char c = DAT_002cfc8c->k8b.C();
        if (c == 0 && !(self->mode == 2 && self->f54 == 1) && !(self->mode == 3 && self->f48->f30c5 != 0)
            && !(self->mode == 4 && self->f48->f30c5 != 0)) {
            if (self->f5a != 0) {
                FUN_001b3e2c(DAT_0034179c);
                FUN_001b1c44(DAT_0034179c, 4);
                FUN_0023466c(DAT_0034a678);
            } else {
                FUN_002ab8fc(self, 1);
                FUN_001b1c44(DAT_0034179c, 4);
            }
        } else if (DAT_002cfc8c->k8a.a == 0 && self->mode != 0) {
            self->f50 = (cur + 3) % 4;
        } else if (DAT_002cfc8c->k8a.b == 0 && self->mode != 0) {
            self->f50 = (cur + 1) % 4;
        } else if (self->f5a != 0) {
            if (DAT_002cfc8c->k89.d == 0 && self->mode != 0) {
                self->f50 = (cur + 3) % 4;
            } else if (DAT_002cfc8c->k89.b == 0 && self->mode != 0) {
                self->f50 = (cur + 1) % 4;
            } else if (DAT_002cfc8c->k8b.b == 0) {
                if ((self->mode != 2 || FUN_002af274(DAT_003415a8 + 0x87128) > 0)
                    && (self->mode != 3 || self->f48->tbl[self->f48->NotFlag()].v > 0)
                           && (self->mode != 4 || self->f48->tbl[self->f48->NotFlag()].v > 0)) {
                    FUN_002ab8fc(self, 0);
                    FUN_001b1c44(DAT_0034179c, 3);
                }
            }
        } else {
            switch (self->mode) {
            case 1:
                if (DAT_002cfc8c->k8b.a == 0) {
                    self->Set54((self->f54 + 1) % 2);
                    FUN_002a5e3c(self->f40, self->f54);
                    FUN_001b1c44(DAT_0034179c, 6);
                } else if (DAT_002cfc8c->k8b.b == 0 && self->f59 == 0 && self->f40->f884 == 13) {
                    self->p5c = StrPair(FUN_002af0d4(DAT_003415a8 + 0x87128));
                    FUN_00011090(self->f90, FUN_0004577c(&self->p5c), 150);
                    self->p74 = StrPair(FUN_001fea10(17, 13, 3));
                    self->f8c->p70->f1c = FUN_0004577c(&self->p74);
                    self->f8c->p70->f20 = self->f90;
                    FUN_00199244(self->f8c);
                    self->f8c->p70->f30 = 24;
                    VB *b = self->f40;
                    b->f178->m1(1);
                    b->f17c = 0;
                    self->f59 = 1;
                    FUN_001b1c44(DAT_0034179c, 3);
                    FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Vec4(0.0f, 0.0f, 0.0f, 0.0f), Vec4(0.0f, 0.0f, 0.0f, 0.75f), 1, 0, 0);
                    FUN_00103628(DAT_0034b354, 1);
                }
                break;
            case 2:
                if (FUN_002af274(DAT_003415a8 + 0x87128) > 0) {
                    if (DAT_002cfc8c->k8b.b == 0) {
                        if (self->f54 == 0) {
                            self->Set54(1);
                            FUN_002a7218(self->f44, self->f54);
                            FUN_002a57ec(self->f3c, self->mode - 1, self->f54);
                            FUN_001b1c44(DAT_0034179c, 3);
                        }
                    } else if (DAT_002cfc8c->k8b.c == 0) {
                        if (self->f54 == 1) {
                            self->Set54(0);
                            FUN_002a7218(self->f44, self->f54);
                            FUN_002a57ec(self->f3c, self->mode - 1, self->f54);
                            FUN_001b1c44(DAT_0034179c, 4);
                        }
                    } else if (DAT_002cfc8c->k8b.d == 0 && self->f54 == 0) {
                        FUN_00114168(DAT_003415ac, 1, FUN_001fea10(17, 19, 0), 0, 0);
                        self->f58 = 1;
                        VCc *cc = self->f44;
                        cc->f358->m1(1);
                        cc->f360 = 0;
                        FUN_001b1c44(DAT_0034179c, 3);
                    }
                }
                break;
            case 3:
            case 4:
                if (self->f48->tbl[self->f48->NotFlag()].v > 0) {
                    if (DAT_002cfc8c->k8b.a == 0) {
                        self->Set54((self->f54 + 1) % 3);
                        FUN_002a9114(self->f48, self->f54, 0);
                        FUN_002a9370(self->f48, self->f48->f30c5, 1);
                        FUN_001b1c44(DAT_0034179c, 6);
                    } else if (c == 0) {
                        FUN_002a9370(self->f48, 0, 1);
                        FUN_002a57ec(self->f3c, self->mode - 1, self->f48->f30c5);
                        FUN_002ab8fc(self, 1);
                        FUN_001b1c44(DAT_0034179c, 4);
                    } else if (DAT_002cfc8c->k8b.d == 0) {
                        FUN_002a9370(self->f48, !self->f48->f30c5, 1);
                        FUN_002a57ec(self->f3c, self->mode - 1, self->f48->f30c5);
                        FUN_001b1c44(DAT_0034179c, 1);
                    }
                }
                break;
            }
        }
    }
    if (cur != self->f50) {
        FUN_002abb70(self, self->f50 + 1);
        FUN_002ab8fc(self, 1);
        FUN_001b1c44(DAT_0034179c, 6);
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
