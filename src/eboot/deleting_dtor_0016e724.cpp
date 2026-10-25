/* HSTMATCH module=EBOOT.BIN start=0x0016e724 end=0x0016f45c symbol=FUN_0016e724 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor (short flag) of a menu/scene object: state switch on +0x78, eleven owned pointer vectors emptied with operator delete, owned table slots in DAT_0034b340 released when state 2, then member and base destruction written out explicitly. Matching idioms: `#pragma opt_strength_reduction off`; the nested null checks of inlined member destructors spelled as repeated `p != 0` tests; IsTwo() and Idle() as bool-temp inlines; the excluded-mode test is a switch with an empty case list and a default call. */
#pragma opt_strength_reduction off
extern "C" {
extern char DAT_003090ac;
extern char DAT_003070bc;
extern char DAT_00311170;
extern char DAT_0034179c;
extern int DAT_0034a678;
extern int DAT_0034a67c;
extern int DAT_003386c8;
extern unsigned char DAT_00341d93;
extern int DAT_00341518;
extern void FUN_00000a00(void *);
extern void FUN_0001f0f0(void *, int);
extern void FUN_00050bb8(void *, int, int, int, int);
extern void FUN_00064a08(void *, int);
extern void FUN_00066338(void *, int);
extern void FUN_00103628(void *, int);
extern void FUN_0016b6c8(int);
extern void FUN_00170b30(void *, int);
extern void FUN_0016fbf4(void *);
extern void FUN_0016fc48(void *);
extern void FUN_0016fca4(void *);
extern void FUN_00170ebc(void *);
extern void FUN_00179a70(void *, int);
extern void FUN_00179ca4(void *, int);
extern void FUN_00179e50(void *, int);
extern void FUN_001b2da8(void *);
extern void FUN_001fe0f4(int);
extern void FUN_001fed58(void);
extern void FUN_001ff5a4(void);
extern void FUN_00204394(void);
extern void FUN_002a4938(void);
}

struct VC { virtual ~VC(); };
extern "C" VC *DAT_0034b340[];

struct VW {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};
struct Game {
    char pad0[0x54];
    VW *w54;
    VW **w58;
    VW *w5c;
    VW *w60;
    VW ***w64;
};
extern "C" Game *DAT_003415ac;

struct Alloc {};
struct Iter {
    void **p;
    Iter(void **q) : p(q) {}
    Iter &operator++() { ++p; return *this; }
    void *&operator*() const { return *p; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }

struct Elem {
    int id;
    char pad4[4];
    unsigned char f8;
    char pad9[2];
    unsigned char fb;
    unsigned char fc;
    bool Idle() const { bool r; if (f8 != 0 || fb != 0 || fc != 0) r = false; else r = true; return r; }
};

struct PtrVec {
    void **data;
    unsigned size;
    unsigned cap;
    unsigned Size() const { return size; }
    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + size); }
    void shrink(int n, Alloc) { size -= n; }
    void DeleteAll()
    {
        for (Iter it = begin(); it != end(); ++it) {
            if (*it != 0)
                FUN_00000a00(*it);
        }
        int n = size;
        shrink(n, Alloc());
    }
};

struct Group {
    char pad0[0xc];
    PtrVec v;
    char o[0x24 - 0x18];
};

struct Res {
    void *vptr;
    char pad4[0xc];
    char a[0x10];
    char b[0x10];
};

struct Self {
    void *vptr;
    char pad4[0x3e - 4];
    unsigned char m3e;
    unsigned char m3f;
    char pad40[3];
    unsigned char m43;
    char pad44[2];
    unsigned char m46;
    char pad47[0x4c - 0x47];
    unsigned char m4c;
    unsigned char m4d;
    unsigned char m4e;
    unsigned char m4f;
    char pad50[4];
    int m54;
    int m58;
    char pad5c[0x78 - 0x5c];
    int state;
    char pad7c[0x96 - 0x7c];
    unsigned char m96;
    char pad97[0xbc - 0x97];
    int mbc;
    char padc0[0x174 - 0xc0];
    VC *p174;
    VC *p178;
    VC *p17c;
    char pad180[0x1a4 - 0x180];
    PtrVec v1a4;
    PtrVec v1b0;
    PtrVec v1bc;
    PtrVec v1c8;
    int pad1d4;
    PtrVec v1d8;
    PtrVec v1e4;
    PtrVec v1f0;
    PtrVec v1fc;
    PtrVec v208;
    Res r214;
    Res r244;
    Res r274;
    char pad2a4[0x3e8 - 0x2a4];
    unsigned char *(*f3e8)(int);
    char pad3ec[0x4f0 - 0x3ec];
    Group g4f0;
    Group g514;
    char pad538[0x558 - 0x538];
    int (*f558)();
    char pad55c[0x5c0 - 0x55c];
    char o5c0[4];
    bool IsTwo() const { bool r = false; if (state == 2) r = true; return r; }
};

static inline void DestroyRes(Res *r)
{
    if (r != 0) {
        r->vptr = &DAT_003070bc;
        if (r->b != 0 && r->b != 0 && r->b != 0 && r->b != 0)
            FUN_00066338(r->b, 0);
        if (r->a != 0 && r->a != 0 && r->a != 0 && r->a != 0)
            FUN_00066338(r->a, 0);
        FUN_00064a08(r, 0);
    }
}

static inline void DestroyGroup(Group *g)
{
    if (g != 0) {
        if (g->o != 0 && g->o != 0)
            FUN_00179ca4(g->o, 0);
        if (&g->v != 0 && &g->v != 0)
            FUN_00179a70(&g->v, 0);
    }
}

static inline void DestroyVec(PtrVec *v)
{
    if (v != 0 && v != 0)
        FUN_00179a70(v, 0);
}

extern "C" Self *FUN_0016e724(Self *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_003090ac;
        FUN_001fe0f4(0);
        bool b = false;
        switch (self->state) {
        case 1:
            b = true;
            if (self->m3e) {
                if (!self->m96)
                    FUN_00170b30(self, self->m58);
            } else if (self->m3f) {
                FUN_00170b30(self, self->m58);
            } else {
                FUN_00170b30(self, self->m54);
            }
            break;
        case 2:
            if (self->m43 != 0) {
                bool found = false;
                int id = self->f558();
                unsigned char *p = self->f3e8(id);
                unsigned i = 0;
                if (self->g4f0.v.size != 0) {
                    do {
                        Elem *e = (Elem *)self->g4f0.v.data[i];
                        if (e->id == id) {
                            if (!e->Idle()) {
                                found = true;
                                break;
                            }
                        }
                        i++;
                    } while (i < self->g4f0.v.Size());
                }
                if (*p - 4u > 1)
                    found = true;
                if (found)
                    FUN_0016fbf4(self);
                else
                    b = true;
            } else {
                FUN_0016fbf4(self);
                FUN_0016fc48(self);
                if (DAT_0034a678 != 0x30 && DAT_0034a678 != 0x29)
                    FUN_002a4938();
            }
            if (self->m4c)
                DAT_00341d93 = 0;
            break;
        case 3:
        case 4:
            FUN_001ff5a4();
            FUN_002a4938();
            if (self->m4c)
                DAT_00341d93 = 0;
            break;
        }
        if (b) {
            if (DAT_003386c8 != 0) {
                switch (DAT_0034a67c) {
                case 0x25:
                case 0x26:
                case 0x28:
                case 0x2d:
                case 0x2f:
                case 0x40:
                case 0x42:
                    break;
                default:
                    FUN_0016b6c8(self->mbc);
                    break;
                }
            }
        }
        if (self->m46)
            FUN_0016fca4(self);
        self->g4f0.v.DeleteAll();
        self->g514.v.DeleteAll();
        self->v1a4.DeleteAll();
        self->v1b0.DeleteAll();
        self->v1bc.DeleteAll();
        self->v1c8.DeleteAll();
        self->v1d8.DeleteAll();
        self->v1e4.DeleteAll();
        self->v1f0.DeleteAll();
        self->v1fc.DeleteAll();
        self->v208.DeleteAll();
        FUN_00050bb8(&DAT_00311170, 0, 0, 0, 0xff);
        FUN_00204394();
        FUN_001b2da8(&DAT_0034179c);
        if (self->IsTwo() && self->m4d) {
            if (self->m4e) {
                VC *q = DAT_0034b340[self->m54];
                if (q != 0) {
                    delete q;
                    DAT_0034b340[self->m54] = 0;
                }
            }
            if (self->m4f) {
                VC *q = DAT_0034b340[self->m58];
                if (q != 0) {
                    delete q;
                    DAT_0034b340[self->m58] = 0;
                }
            }
            if (!self->m4e && !self->m4f) {
                if (DAT_0034b340[0] != 0) {
                    delete DAT_0034b340[0];
                    DAT_0034b340[0] = 0;
                }
                if (DAT_0034b340[2] != 0) {
                    delete DAT_0034b340[2];
                    DAT_0034b340[2] = 0;
                }
            }
        }
        if (self->p178 != 0) {
            delete self->p178;
            self->p178 = 0;
        }
        if (self->p174 != 0) {
            delete self->p174;
            self->p174 = 0;
        }
        if (self->p17c != 0) {
            delete self->p17c;
            self->p17c = 0;
        }
        DAT_00341518 = 0;
        FUN_001fed58();
        if (DAT_003415ac != 0) {
            FUN_00103628(DAT_003415ac, 1);
            Game *g = DAT_003415ac;
            g->w54->v5(-1);
            (*g->w58)->v5(-1);
            g->w5c->v5(-1);
            g->w60->v5(-1);
            (**g->w64)->v5(-1);
            FUN_00170ebc(self);
        }
        if (self->o5c0 != 0 && self->o5c0 != 0)
            FUN_00179e50(self->o5c0, 0);
        DestroyGroup(&self->g514);
        DestroyGroup(&self->g4f0);
        DestroyRes(&self->r274);
        DestroyRes(&self->r244);
        DestroyRes(&self->r214);
        DestroyVec(&self->v208);
        DestroyVec(&self->v1fc);
        DestroyVec(&self->v1f0);
        DestroyVec(&self->v1e4);
        DestroyVec(&self->v1d8);
        DestroyVec(&self->v1c8);
        DestroyVec(&self->v1bc);
        DestroyVec(&self->v1b0);
        DestroyVec(&self->v1a4);
        FUN_0001f0f0(self, 0);
        if (0 < flag)
            FUN_00000a00(self);
    }
    return self;
}
