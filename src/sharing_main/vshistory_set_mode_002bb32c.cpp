/* HSTMATCH module=hstp_trans_main.prx start=0x002bb32c end=0x002bb62c symbol=FUN_002bb32c lang=c++ data=0x003abcf8 */
/* Hand-written reconstruction (port of src/eboot/vshistory_set_mode_002abb70.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
extern char DAT_003a9b2c;
extern char DAT_003b7ebc[];
extern char DAT_003b3e6c[];
extern char DAT_003eaad8[];
void FUN_002bb62c(Self *, int);
void FUN_002b69a8(VC *, int);
void FUN_002b55cc(VB *, int);
void FUN_0001c684(char *, int, const char *);
void *FUN_00000bcc(unsigned);
VA *FUN_002b4b00(void *);
VB *FUN_002b5194(void *);
VC *FUN_002b62f8(void *);
VD *FUN_002b7e50(void *);
void FUN_0001c73c(char *);
int FUN_00010184(int, int);
void FUN_0001bb2c(char *, int, int);
void FUN_0001c5f4(char *, const char *);
void FUN_001c16b4(char *, int);
int FUN_0001c848();
int FUN_0001c8a0();
void FUN_000104e0(int);
void FUN_001c1f44(char *, int);
void FUN_002bb0b8(Self *, int);
void FUN_002b88d0(VD *, int, int);
void FUN_002b8b2c(VD *, int, int);
}

extern "C" void FUN_002bb32c(Self *self, int mode)
{
    if (mode != self->mode) {
        self->mode = mode;
        FUN_002bb62c(self, 0);
        switch (mode) {
        case 0: {
            self->f50 = 0;
            self->f58 = 0;
            self->f59 = 0;
            self->p5c = StrPair(&DAT_003a9b2c);
            FUN_0001c684(DAT_003b7ebc, 1, "menu/adhoc_vshistory.xb");
            VA *a = (VA *)FUN_00000bcc(236);
            if (a)
                a = FUN_002b4b00(a);
            self->f3c = a;
            VB *b = (VB *)FUN_00000bcc(5892);
            if (b)
                b = FUN_002b5194(b);
            self->f40 = b;
            VC *c = (VC *)FUN_00000bcc(5780);
            if (c)
                c = FUN_002b62f8(c);
            self->f44 = c;
            VD *d = (VD *)FUN_00000bcc(12600);
            if (d)
                d = FUN_002b7e50(d);
            self->f48 = d;
            FUN_0001c73c(DAT_003b7ebc);
            int buf = FUN_00010184(0x40, 0x100000);
            FUN_0001bb2c(DAT_003b3e6c, buf, 0x100000);
            FUN_0001c5f4(DAT_003b7ebc, "menu/adhoc_vshistory_bgm.xb");
            FUN_001c16b4(DAT_003eaad8, 4);
            FUN_0001c73c(DAT_003b7ebc);
            int p = FUN_0001c848();
            int q = FUN_0001c8a0();
            FUN_0001bb2c(DAT_003b3e6c, p, q);
            FUN_000104e0(buf);
            FUN_001c1f44(DAT_003eaad8, 4);
            self->f3c->m1();
            self->f40->m1();
            self->f44->m1();
            self->f48->m1();
            FUN_002bb0b8(self, 1);
            break;
        }
        case 1:
            FUN_002b55cc(self->f40, 0);
            break;
        case 2:
            FUN_002b69a8(self->f44, 0);
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
            FUN_002b88d0(o, o->f30c0, 0);
            FUN_002b88d0(self->f48, 0, 0);
            FUN_002b8b2c(self->f48, 0, 1);
            break;
        }
        }
    }
}
