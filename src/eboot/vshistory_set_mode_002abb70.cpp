/* HSTMATCH module=EBOOT.BIN start=0x002abb70 end=0x002abe70 symbol=FUN_002abb70 lang=c++ data=0x00302c1c */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: a switch over the mode (cases 3 and 4 share one body, MWCC tests 4,3,2,1,0 in reverse label order) whose case 0 assigns a temporary StrPair (String + 12-byte container; inline ctor/dtor/operator= calling the out-of-line helpers, same class as 0x22d848) to the member; the two menu strings are anonymous .data placed with data=0x00302c1c and the empty-string argument is the pooled DAT_00300a90; `bool NotFlag() { return !f30c4; }` gives the sltu/xori/andi index; names and types await human review. */
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

struct VA {
    virtual void m0();
    virtual void m1();
};
struct VB {
    virtual void m0();
    virtual void m1();
};
struct VC {
    virtual void m0();
    virtual void m1();
};
struct Sub {
    char pad[0xd8];
    int fd8;
    int fdc;
};
struct Ent12 {
    int v;
    int pad[2];
};
struct VD {
    virtual void m0();
    virtual void m1();
    char pad4[0x1038 - 4];
    Sub *f1038;
    char pad103c[0x30c0 - 0x103c];
    int f30c0;
    bool f30c4;
    char pad30c5[3];
    int f30c8;
    int f30cc;
    int f30d0;
    char pad30d4[0x30f0 - 0x30d4];
    Ent12 tbl[2];
    bool NotFlag() { return !f30c4; }
};

struct Self {
    char pad0[0x3c];
    VA *f3c;
    VB *f40;
    VC *f44;
    VD *f48;
    int mode;
    int f50;
    char pad54[4];
    char f58;
    char f59;
    StrPair p5c;
};

extern "C" {
extern char DAT_00300a90;
extern char DAT_0030ebf4[];
extern char DAT_0030ab9c[];
extern char DAT_0034179c[];
void FUN_002abe70(Self *, int);
void FUN_002a7218(VC *, int);
void FUN_002a5e3c(VB *, int);
void FUN_0001cad0(char *, int, const char *);
void *FUN_00000bcc(unsigned);
VA *FUN_002a5370(void *);
VB *FUN_002a5a04(void *);
VC *FUN_002a6b68(void *);
VD *FUN_002a8694(void *);
void FUN_0001cb88(char *);
int FUN_00010184(int, int);
void FUN_0001bfb4(char *, int, int);
void FUN_0001ca58(char *, const char *);
void FUN_001b3378(char *, int);
int FUN_0001cbfc();
int FUN_0001cc54();
void FUN_000104e0(int);
void FUN_001b3ce8(char *, int);
void FUN_002ab8fc(Self *, int);
void FUN_002a9114(VD *, int, int);
void FUN_002a9370(VD *, int, int);
}

extern "C" void FUN_002abb70(Self *self, int mode)
{
    if (mode != self->mode) {
        self->mode = mode;
        FUN_002abe70(self, 0);
        switch (mode) {
        case 0: {
            self->f50 = 0;
            self->f58 = 0;
            self->f59 = 0;
            self->p5c = StrPair(&DAT_00300a90);
            FUN_0001cad0(DAT_0030ebf4, 1, "menu/adhoc_vshistory.xb");
            VA *a = (VA *)FUN_00000bcc(236);
            if (a)
                a = FUN_002a5370(a);
            self->f3c = a;
            VB *b = (VB *)FUN_00000bcc(5892);
            if (b)
                b = FUN_002a5a04(b);
            self->f40 = b;
            VC *c = (VC *)FUN_00000bcc(5780);
            if (c)
                c = FUN_002a6b68(c);
            self->f44 = c;
            VD *d = (VD *)FUN_00000bcc(12600);
            if (d)
                d = FUN_002a8694(d);
            self->f48 = d;
            FUN_0001cb88(DAT_0030ebf4);
            int buf = FUN_00010184(0x40, 0x100000);
            FUN_0001bfb4(DAT_0030ab9c, buf, 0x100000);
            FUN_0001ca58(DAT_0030ebf4, "menu/adhoc_vshistory_bgm.xb");
            FUN_001b3378(DAT_0034179c, 4);
            FUN_0001cb88(DAT_0030ebf4);
            int p = FUN_0001cbfc();
            int q = FUN_0001cc54();
            FUN_0001bfb4(DAT_0030ab9c, p, q);
            FUN_000104e0(buf);
            FUN_001b3ce8(DAT_0034179c, 4);
            self->f3c->m1();
            self->f40->m1();
            self->f44->m1();
            self->f48->m1();
            FUN_002ab8fc(self, 1);
            break;
        }
        case 1:
            FUN_002a5e3c(self->f40, 0);
            break;
        case 2:
            FUN_002a7218(self->f44, 0);
            break;
        case 3:
        case 4: {
            VD *o = self->f48;
            o->f30c4 = (mode == 3);
            o->f30c8 = 0;
            o->f30cc = 0;
            int v = o->tbl[o->NotFlag()].v;
            o->f30d0 = v;
            Sub *s = o->f1038;
            s->fd8 = v;
            s->fdc = 5;
            FUN_002a9114(o, o->f30c0, 0);
            FUN_002a9114(self->f48, 0, 0);
            FUN_002a9370(self->f48, 0, 1);
            break;
        }
        }
    }
}
